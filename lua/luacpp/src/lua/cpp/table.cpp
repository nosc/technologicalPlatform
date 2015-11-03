#include "lua/cpp/coroutine.h"
#include "lua/cpp/table.h"
#include "lua/cpp/typetemplates.h"
#include "lua/cpp/function.h"

namespace lua {
namespace cpp
{

Table::Table(std::shared_ptr<lua_State> state, int index) : Reference(state, index)
{
    assert(GetType() == Value::table);
}

Value Table::GetTypeOfValueAt(std::string key) const
{
    PushToStack(state.get());
    lua_pushlstring(state.get(), key.c_str(), key.size());
    lua_gettable(state.get(), -2);
    Value res = (Value::Values)lua_type(state.get(), -1);
    lua_pop(state.get(), 2);
    return res;
}

Value Table::GetTypeOfValueAt(int key) const
{
    PushToStack(state.get());
    lua_pushinteger(state.get(), key);
    lua_gettable(state.get(), -2);
    Value res = (Value::Values)lua_type(state.get(), -1);
    lua_pop(state.get(), 2);
    return res;
}

void Table::ForAllStringKeys(std::function<void(std::string, Value)> stringKeys) const
{
    PushToStack(state.get());
    lua_pushnil(state.get());  /* first key */

    while (lua_next(state.get(), -2) != 0)
    {

        if ((Value::Values)lua_type(state.get(), -2) == Value::string)
        {
            const char* key = lua_tostring(state.get(), -2);
            auto valueType = (Value::Values)lua_type(state.get(), -1);
            stringKeys(key, valueType);
        }
        lua_pop(state.get(), 1);
    }
    lua_pop(state.get(), 1);
}

void Table::ForAllIntegerKeys(std::function<void(int, Value)> integerKeys) const
{
    PushToStack(state.get());
    lua_pushnil(state.get());  /* first key */

    while (lua_next(state.get(), -2) != 0)
    {
        if ((Value::Values)lua_type(state.get(), -2) == Value::number)
        {
            int key = lua_tointeger(state.get(), -2);
            auto valueType = (Value::Values)lua_type(state.get(), -1);
            integerKeys(key, valueType);
        }
        lua_pop(state.get(), 1);
    }
    lua_pop(state.get(), 1);
}


}
}

