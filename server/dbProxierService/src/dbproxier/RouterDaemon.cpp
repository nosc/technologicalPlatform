#include "include/dbproxier/RouterDaemon.h"

#include <QTcpSocket>
#include <QtServiceBase>
#include <QDateTime>

#include "dbproxier/Channel.h"
#include "dbproxier/ExecutorFactory.h"

namespace dbproxier {

RouterDaemon::RouterDaemon(quint16 port, QObject *parent)
    : QTcpServer(parent)    
{
    rewritePrograms();

    listen(QHostAddress::Any, port);
}

void RouterDaemon::incomingConnection(int socket)
{
    if (_disabled)
        return;

    // When a new client connects, the server constructs a QTcpSocket and all
    // communication with the client is done over this QTcpSocket. QTcpSocket
    // works asynchronously, this means that all the communication is done
    // in the two slots readClient() and discardClient().
    QTcpSocket* s = new QTcpSocket(this);
    IChannel* channel = new Channel(_executorFactory.data()->factory());

    _channels.insert(s, channel);

    connect(s, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(s, SIGNAL(disconnected()), this, SLOT(discardClient()));
    s->setSocketDescriptor(socket);

    QtServiceBase::instance()->logMessage("New Connection");
}

void RouterDaemon::pause()
{
    _disabled = true;
}

void RouterDaemon::resume()
{
    _disabled = false;
}

void RouterDaemon::readClient()
{
    if (_disabled)
        return;

    // This slot is called when the client sent data to the server. The
    // server looks if it was a get request and sends a very simple HTML
    // document back.
    QTcpSocket* socket = (QTcpSocket*)sender();

    IChannel* channel =_channels.value(socket);
    if (channel == 0)
        return;

    while (socket->canReadLine())
    {
        QStringList tokens = QString(socket->readLine()).split("\r\n", QString::SkipEmptyParts);
        for (int i=0; i <tokens.size(); ++i)
            channel->input(tokens[i]);
    }

    while (channel->hasOutput())
    {
        QByteArray data;
        data.append(channel->output());
        data.append("\n\r");
        socket->write(data);        
    }

    if (channel->finished())
    {
        // _channels.remove(socket);

        // delete channel;
        // socket->waitForBytesWritten(10);
        // socket->close();
        // socket->deleteLater();
    }
}

void RouterDaemon::discardClient()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    socket->deleteLater();

    QtServiceBase::instance()->logMessage("Connection closed");
}

void RouterDaemon::rewritePrograms()
{
    QDir _dir = QDir::current();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "main");
    db.setHostName("localhost");
    db.setDatabaseName("virtual_builder");
    db.setUserName("virtual_builder");
    db.setPassword("virtual_builder");
    db.open();

    _executorFactory.reset (new IExecutorFactory::Holder(new ExecutorFactory(_dir, "main")));
}
}
