#include "lua/cpp/reference.h"
#include "lua/cpp/table.h"

namespace lua {
namespace cpp
{

Reference::Reference(std::shared_ptr<lua_State> state, int index) : state(state)
{
	lua_pushvalue(state.get(), index);
	ref = luaL_ref(state.get(), LUA_REGISTRYINDEX);;
}

Reference::Reference(const Reference& other)
{
	*this = other;
}

Reference& Reference::operator=(const Reference& other)
{
	state = other.state;
	other.PushToStack(state.get());
	ref = luaL_ref(state.get(), LUA_REGISTRYINDEX);
	return *this;
}

Reference::~Reference()
{
	luaL_unref(state.get(), LUA_REGISTRYINDEX, ref);
}

void Reference::PushToStack(lua_State* currentState) const
{
	lua_rawgeti(currentState, LUA_REGISTRYINDEX, ref);
}

Value Reference::GetType() const
{
	PushToStack(state.get());
    Value val = (Value::Values)lua_type(state.get(), -1);
	lua_pop(state.get(), 1);
	return val;
}

std::shared_ptr<lua_State> Reference::GetState()
{
	return state;
}

Table Reference::GetMetaTable() const
{
	PushToStack(state.get());
	int res = lua_getmetatable(state.get(), -1);
	assert(res != 0);
    Table table = Table(state, -1);
	lua_pop(state.get(), 2);
	return table;
}

}
}
