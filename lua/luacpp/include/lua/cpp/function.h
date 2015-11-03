#ifndef LUAFUNCTION_H
#define LUAFUNCTION_H

#include "lua/cpp/genericfunction.h"

namespace lua {
namespace cpp
{

template<typename SIG>
class Function : public GenericFunction<SIG>
{
    typedef typename std::shared_ptr< std::function<SIG> > funcPtr;
    funcPtr func;

public:
    Function(std::shared_ptr<lua_State> state, int index, funcPtr func = funcPtr()) : GenericFunction<SIG>(state, index), func(func)
    {
    }
};


}
}

#endif // LUAFUNCTION_H
