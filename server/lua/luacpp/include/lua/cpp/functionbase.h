#ifndef LUAFUNCTIONBASE_H
#define LUAFUNCTIONBASE_H

#include <string>

#include "lua/cpp/reference.h"

namespace lua {
namespace cpp
{

class FunctionBase : public Reference
{
public:
    FunctionBase(std::shared_ptr<lua_State> state, int index);
};

}
}


#endif // LUAFUNCTIONBASE_H
