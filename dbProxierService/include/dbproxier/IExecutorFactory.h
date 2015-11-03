#ifndef IEXECUTORFACTORY
#define IEXECUTORFACTORY

#include <QAtomicInt>
#include <string>

namespace dbproxier
{
    struct IExecutor;
}

namespace dbproxier
{

struct IExecutorFactory
{
    IExecutorFactory() : _refsCounter(0) { }

    virtual IExecutor* createExecutor(const std::string& name) = 0;
    virtual ~IExecutorFactory() {}

    struct Holder
    {
        Holder(IExecutorFactory* factory)
        {
            _factory = factory;
            _factory->incRefs();
        }

        ~Holder() { _factory->decRefs(); }

    public:
        IExecutorFactory *factory() const { return _factory; }

        IExecutorFactory* operator ->() { return _factory; }

    private:
        IExecutorFactory* _factory;
    };

private:
    void incRefs() { ++_refsCounter; }
    void decRefs() { if (--_refsCounter == 0) delete this; }

private:
    QAtomicInt _refsCounter;
};



}
#endif // IEXECUTORFACTORY

