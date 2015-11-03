#include "dbproxier/ExecutorFactory.h"

#include <QSqlQuery>
#include <QVariant>

#include "dbproxier/IQuery.h"

#include <dbproxier/IExecutor.h>

#include "lua/cpp/Machine.h"


namespace dbproxier
{

namespace
{

struct Query : public IQuery
{

public:
    Query (QString connectionName, std::string text)
    {
        QSqlDatabase db = QSqlDatabase::database(connectionName);

        _query = new QSqlQuery(db);
        _query->prepare(QString::fromStdString(text));
    }

    ~Query()
    {
        if (_query != 0)
            delete _query;
    }

    QSqlQuery* take()
    {
        QSqlQuery* result = _query;
        _query = 0;
        return result;
    }

    // IQuery interface
    virtual void set(std::string name, std::wstring value)
    {
        auto name_ = QString::fromStdString(name);
        auto value_ = QString::fromStdWString(value);

        _query->bindValue(name_, QVariant(value_));
    }

private:
    QSqlQuery* _query;

};

using namespace lua::cpp;

class LuaExecutor : public IExecutor
{
public:
    LuaExecutor(std::shared_ptr<lua::cpp::Machine> machine)
        : _machine(machine)
        , _argsTable(machine->CreateTable())
        , _queryGeneratorFunction(machine->GetGlobalEnvironment().Get< Function<Userdata<Query>(Table)> >("generateQuery"))
        , _result(0)
    {
    }

    // IExecutor interface
public:
    virtual void setArgument(const QString &name, const QString &value);
    virtual QString execute();
    virtual QSqlQuery *result() {return _result; }

private:
    std::shared_ptr<lua::cpp::Machine> _machine;
    lua::cpp::Table _argsTable;
    lua::cpp::Function<Userdata<Query>(Table)> _queryGeneratorFunction;
    QSqlQuery* _result;
};


void LuaExecutor::setArgument(const QString &name, const QString &value)
{
    auto argName = name.toStdString();
    auto argValue = value.toStdWString();

    _argsTable.Set(argName, argValue);
}

QString LuaExecutor::execute()
{
    Userdata<Query> result = _queryGeneratorFunction.Invoke(_argsTable);

    Query* query = dynamic_cast<Query*>(result.RetrieveData());
    _result = query->take();

    return QString();
}
}

ExecutorFactory::ExecutorFactory(const QDir& programsPath, const QString& connectionName)
    : _connectionName(connectionName)
{
   QString luaFilter("*.lua");
   QStringList commandFiles = programsPath.entryList(QStringList(luaFilter));

   for (int i=0; i < commandFiles.size(); ++i)
   {
       QString filename = commandFiles[i];
       QFile microProgramFile(filename);

       if (!microProgramFile.open(QIODevice::ReadOnly))
           continue;

       std::string microProgramText = microProgramFile.readAll().toStdString();

       _commands.insert(commandFiles[i].toStdString(), microProgramText);
   }
}

IExecutor *ExecutorFactory::createExecutor(const std::string &name)
{
    const std::string command = _commands.value(name, "");
    if (command.empty())
        return 0;

    using namespace lua::cpp;
    std::shared_ptr<Machine> machine(new Machine);
    machine->LoadStandardLibraries();
    machine->RunScript(command);

    registerQuery(machine.get());

    return new LuaExecutor(machine);
}

void ExecutorFactory::registerQuery(lua::cpp::Machine *machine)
{
    lua::cpp::Machine & machine_ = *machine;

    auto queryConstructor = machine_.CreateFunction< Userdata<Query>(std::string text) >(
    [&](std::string text) -> Userdata<Query>
    {
        // Create the userdata instance
        Userdata<Query> query = machine_.CreateUserdata<Query>(
                new Query("main", text)
                );

        // Bind the functions that we want to expose
        query.Bind("bind_value", &Query::set);
        query.Bind("bind_arg", &Query::set);

        return query;
    });

    auto queryType = machine_.CreateTable();
    queryType.Set("new", queryConstructor);
    machine_.GetGlobalEnvironment().Set("Query", queryType);
}

}
