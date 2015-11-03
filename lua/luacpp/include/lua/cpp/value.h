#ifndef LUAVALUE_H
#define LUAVALUE_H

#include <lua/lua.hpp>

namespace lua {
namespace cpp
{

class Value
{
public:
    enum Values
    {
        none = LUA_TNONE,
        nil = LUA_TNIL,
        string = LUA_TSTRING,
        number = LUA_TNUMBER,
        thread = LUA_TTHREAD,
        boolean = LUA_TBOOLEAN,
        function = LUA_TFUNCTION,
        userdata = LUA_TUSERDATA,
        lightuserdata = LUA_TLIGHTUSERDATA,
        table = LUA_TTABLE
    };

    Value(Values value) : _value(value) { }

    bool operator ==(Values right) const { return _value == right; }
    bool operator !=(Values right) const { return _value != right; }

private:
    Values _value;
};


}

}

#endif // LUATYPE_H
