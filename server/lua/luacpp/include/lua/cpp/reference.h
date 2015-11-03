#ifndef LUAREFERENCE_H
#define LUAREFERENCE_H

#include <memory>
#include "lua/cpp/value.h"

#include <lua/lua.hpp>

namespace lua {
namespace cpp
{

class Table;
class Reference
{
    int ref;

protected:
    std::shared_ptr<lua_State> state;

public:
    Reference(std::shared_ptr<lua_State> state, int index);
    Reference(const Reference& other);
    Reference& operator=(const Reference& other);
    virtual ~Reference();

    // push the object to the stack you are working on
    void PushToStack(lua_State* currentState) const;
    Value GetType() const;
    std::shared_ptr<lua_State> GetState();
    Table GetMetaTable() const;
};

}
}

#endif // LUAREFERENCE_H
