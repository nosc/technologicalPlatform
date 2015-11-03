#include "dbProxier/RouterService.h"
#include "dbProxier/RouterDaemon.h"

namespace dbproxier
{

RouterService::RouterService(int argc, char **argv)
    : QtService<QCoreApplication>(argc, argv, "Qt HTTP Daemon")
{
    setServiceDescription("DBProxier service");
    setServiceFlags(QtServiceBase::CanBeSuspended);
}


void RouterService::start()
{
    QCoreApplication *app = application();

#if QT_VERSION < 0x040100
    quint16 port = (app->argc() > 1) ?
                QString::fromLocal8Bit(app->argv()[1]).toUShort() : 8080;
#else
    const QStringList arguments = QCoreApplication::arguments();
    quint16 port = (arguments.size() > 1) ?
                arguments.at(1).toUShort() : 8080;
#endif
    _daemon = new RouterDaemon(port, app);

    if (!_daemon->isListening()) {
        logMessage(QString("Failed to bind to port %1").arg(_daemon->serverPort()), QtServiceBase::Error);
        app->quit();
    }

    resume();
}

void RouterService::pause()
{
    _daemon->pause();
}

void RouterService::resume()
{
    _daemon->resume();
}


}
