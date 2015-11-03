#ifndef CHANNEL_H
#define CHANNEL_H

#include "dbProxier/IChannel.h"

#include <QString>
#include <QStringList>
#include <QScopedPointer>
#include <QMap>
#include <QSqlQuery>


#include "dbProxier/IExecutorFactory.h"

namespace dbproxier
{

class Channel : public IChannel
{
public:
    Channel(IExecutorFactory* factory);

    // IChannel interface
private:
    virtual void input(const QString &data);
    virtual bool hasOutput() const;
    virtual QString output();
    virtual bool finished();

private:
    enum State
    {
        WAITING_COMMAND,
        WAITING_ARGUMENTS,
        WAITING_NEXT,
        FINISHED
    };

    enum Command
    {
        NONE,
        FETCH,
        CUSTOM
    };

private:
    void parseCommand(const QString& command);
    void parseArgument(const QString& argument);
    void fetch(const QString& argument);
    void restart();

private:
    State _state;
    QStringList _output;
    IExecutorFactory::Holder _holder;
    QStringList _systemCommands;

private:
    bool _keepAliveMode;
    Command _currentCommand;
    QString _currentCommandName;
    QScopedPointer<IExecutor> _currentExecutor;
    size_t _queryId;

    QMap<size_t, QSqlQuery*> _activeQueries;
    void execute();
};
}

#endif // CHANNEL_H
