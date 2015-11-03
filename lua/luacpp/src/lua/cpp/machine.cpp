#include "lua/cpp/machine.h"
#include "lua/cpp/userdata.h"

#include <sstream>

namespace lua {
namespace cpp {

std::string LuaGetLastError(lua_State* state)
{
    std::stringstream ss;
    for (int level = 1; level <= lua_gettop(state); level++)
    {
        const char* errorMessage = lua_tostring(state, level);
        if (errorMessage)
        {
            ss << "Error: " << errorMessage << std::endl;
        }
    }

    lua_Debug debugInfo;
    for (int level = 0; lua_getstack(state, level, &debugInfo); level++)
    {
        lua_getinfo(state, "nSlf", &debugInfo);
        ss << "Line: " << debugInfo.currentline << std::endl;
        ss << "Source: " << debugInfo.source << std::endl;

        const char* function = lua_tostring(state, -1);
        if (function)
        {
            ss << "Function: " << function << std::endl;
        }
    }

    return ss.str();
}

Machine::Machine() :
    state(luaL_newstate(), lua_close),
    registry(Table(state, LUA_REGISTRYINDEX)),
    globals(registry.Get<Table>(LUA_RIDX_GLOBALS))
{
}

Machine::Machine(std::shared_ptr<lua_State> state) :
    state(state),
    registry(Table(state, LUA_REGISTRYINDEX)),
    globals(registry.Get<Table>(LUA_RIDX_GLOBALS))

{
}

void Machine::LoadStandardLibraries()
{
    luaL_openlibs(state.get());
}

Table Machine::GetRegistry() const
{
    return registry;
}

Table Machine::GetGlobalEnvironment() const
{
    return globals;
}

Table Machine::CreateTable()
{
    lua_newtable(state.get());
    Table table = Table(state, -1);
    lua_pop(state.get(), 1);
    return table;
}

Coroutine Machine::CreateCoroutine()
{
    lua_newthread(state.get());
    Coroutine thread(state, -1);
    lua_pop(state.get(), 1);
    return thread;
}

std::string Machine::RunScript(std::string script)
{
    int err = luaL_dostring(state.get(), script.c_str());
    if (err != LUA_OK)
    {
        return LuaGetLastError(state.get());
    }
    return "No errors";
}

Machine::~Machine()
{
}


}
}
