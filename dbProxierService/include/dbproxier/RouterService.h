#ifndef ROUTERSERVICE_H
#define ROUTERSERVICE_H

#include <QtService>
#include <QCoreApplication>

namespace dbproxier
{
    class RouterDaemon;
}

namespace dbproxier
{

class RouterService : public QtService<QCoreApplication>
{
public:
    RouterService(int argc, char **argv);

protected:
    void start();
    void pause();
    void resume();

private:
    RouterDaemon *_daemon;
};

}

#endif // ROUTERSERVICE_H
