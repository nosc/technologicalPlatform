#ifndef ICHANNEL
#define ICHANNEL

#include <QString>

namespace dbproxier
{
    struct IChannel
    {
        virtual ~IChannel();

        virtual void input(const QString& data) = 0;
        virtual bool hasOutput() const = 0;
        virtual QString output() = 0;
        virtual bool finished() = 0;
    };
}

#endif // ICHANNEL

