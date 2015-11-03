#ifndef ROUTERDAEMON_H
#define ROUTERDAEMON_H

#include <QTcpServer>

#include "dbProxier/IExecutorFactory.h"

class QTcpSocket;

namespace dbproxier
{
    class IChannel;

}

namespace dbproxier
{

class RouterDaemon : public QTcpServer
{
    Q_OBJECT
public:
    RouterDaemon(quint16 port, QObject* parent = 0);

    void incomingConnection(int socket);

    void pause();

    void resume();

private slots:
    void readClient();
    void discardClient();

private:
    void rewritePrograms();

private:
    bool _disabled;
    QMap<QTcpSocket*, IChannel*> _channels;

    QScopedPointer<IExecutorFactory::Holder> _executorFactory;
};
}

#endif // ROUTERDAEMON_H
