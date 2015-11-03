#ifndef IEXECUTOR
#define IEXECUTOR

#include <QSqlQuery>

namespace dbproxier
{
    struct IExecutor
    {
        virtual void setArgument(const QString& name, const QString& value) = 0;
        virtual QString execute() = 0;
        virtual QSqlQuery* result() = 0;
        virtual ~IExecutor() { }
    };
}

#endif // ICOMMANDEXECUTOR

