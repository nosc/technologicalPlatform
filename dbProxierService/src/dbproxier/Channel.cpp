#include "dbproxier/Channel.h"

#include "dbProxier/IExecutor.h"
#include <QSqlError>

#include <QSqlRecord>
#include <QSqlField>

namespace dbproxier
{

namespace
{
    const char* PACKET_TEXT = "PACKET";
    const char* PACKET_END_TEXT = "/PACKET";
    const char* FETCH_TEXT = "FETCH";
}

Channel::Channel(IExecutorFactory *factory)
    : _state(WAITING_COMMAND)
    , _holder(factory)
    , _keepAliveMode(true)
    , _currentCommand(NONE)
    , _queryId(0)
{

}

void Channel::input(const QString &data)
{
    switch (_state)
    {
        case WAITING_COMMAND:
            parseCommand(data);
        break;

        case WAITING_NEXT:
        break;

        case WAITING_ARGUMENTS:
            parseArgument(data);
        break;

        case FINISHED:
        break;
    }
}

QString dbproxier::Channel::output()
{
    if (_output.empty())
        return QString();

    QString result = _output.front();
    _output.pop_front();
    return result;
}

void Channel::parseCommand(const QString &command)
{
    if (command.endsWith(PACKET_TEXT))
    {
        _keepAliveMode = true;
        _state = WAITING_COMMAND;
        return;
    }

    if (command.endsWith(PACKET_END_TEXT))
    {
        _keepAliveMode = false;
        _state = FINISHED;
        return;
    }

    if (command.endsWith(FETCH_TEXT))
    {
        _currentCommand = FETCH;
        _state = WAITING_ARGUMENTS;
        return;
    }

    _currentExecutor.reset(_holder->createExecutor(command.toStdString()));
    if (_currentExecutor != 0)
    {
        _state = WAITING_ARGUMENTS;
        _currentCommand = CUSTOM;
        _currentCommandName = command;
    }
    else
    {
        _output.append("unknown command");
        restart();
    }
}

void Channel::execute()
{
    const QString& message = _currentExecutor.data()->execute();
    QSqlQuery* result = _currentExecutor.data()->result();
    if (result == 0)
    {
        _output.append("500");
        _output.append(message);
    }
    else
    {
        bool execResult = result->exec();
        if (execResult == true)
        {
            if (result->isSelect())
            {
                _activeQueries.insert(++_queryId, result);
                _output.append(QString("200"));
                _output.append(QString("qieryid=%1").arg(_queryId));
            }
            else
            {
                _output.append("200");
                _output.append("queryid=None");
            }
        }
        else
        {
            _output.append("500 Query Error");
            _output.append(result->lastError().driverText() + "/" + result->lastError().databaseText());
        }

    }

    restart();
}

void Channel::parseArgument(const QString &argument)
{
    if (argument.isEmpty())
        return;

    QString name = argument.section("=", 0, 0);
    QString value = argument.section("=", 1);

    QRegExp nameRegExp("[A-Za-z]*");

    if (name.isEmpty())
        return;

    if (value.isEmpty())
    {
        if (name == "/" + _currentCommandName)
        {
            execute();
            return;
        }

        value = "true";
    }

    switch (_currentCommand)
    {
        case CUSTOM:
            _currentExecutor.data()->setArgument(name, value);
        break;

        case FETCH:
            fetch(value);
            return;

        case NONE:
            return;
        break;
    }
}

void Channel::fetch(const QString &argument)
{
    bool ok = false;
    uint queryId = argument.toUInt(&ok);
    if (ok)
    {
        QSqlQuery* query = _activeQueries.value(queryId, 0);
        if (query != 0)
        {
            if (query->next())
            {
                _output.append(QString("200 %1 next result").arg(queryId));
                const QSqlRecord& row = query->record();

                for (int i=0; i < row.count(); ++i)
                {
                    const QSqlField& field = row.field(i);
                    _output.append(QString("%1=%2").arg(field.name(), field.value().toString()));
                }
            }
            else
            {
                _output.append(QString("201 %1 finsihed").arg(queryId));
                delete query;
                _activeQueries.remove(queryId);
                if (_activeQueries.isEmpty())
                    restart();
            }

            restart();
            return;
        }
    }

    _output.append("404 Unknown identificator");
    restart();
}

void Channel::restart()
{
    _state =_keepAliveMode ? WAITING_COMMAND: FINISHED;
}

bool dbproxier::Channel::finished()
{
    return _state == FINISHED;
}

bool dbproxier::Channel::hasOutput() const
{
    return !_output.isEmpty();
}


}
