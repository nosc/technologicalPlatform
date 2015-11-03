#ifndef IQUERY
#define IQUERY

#include "dbproxier/Core_global.h"
#include <string>

namespace dbproxier
{

struct DBPROXIERCORESHARED_EXPORT IQuery
{
    virtual void set(std::string name, std::wstring value) = 0;
    IQuery();

    virtual ~IQuery();
};

}

#endif // IQUERY

