#ifndef EXECUTORFACTORY
#define EXECUTORFACTORY

#include "dbproxier/IExecutorFactory.h"

#include <QDir>
#include <QMap>

namespace lua
{
    namespace cpp
    {
        class Machine;
    }
}

namespace dbproxier
{

class ExecutorFactory : public IExecutorFactory
{
public:
    ExecutorFactory(const QDir& programsPath, const QString& connectionName);

    // IExecutorFactory interface
public:
    virtual IExecutor *createExecutor(const std::string &name);

private:
    void registerQuery(lua::cpp::Machine* machine);

private:
    QMap<std::string, std::string> _commands;
    QString _connectionName;
};

}

#endif
