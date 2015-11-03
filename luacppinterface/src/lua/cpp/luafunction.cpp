#include <cassert>
#include "lua/cpp/luacoroutine.h"
#include "lua/cpp/luatable.h"
#include "lua/cpp/luatypetemplates.h"
#include "lua/cpp/luafunction.h"

LuaFunctionBase::LuaFunctionBase(std::shared_ptr<lua_State> state, int index) : LuaReference(state, index)
{
	auto type = GetType();
	if (type != LuaType::function)
	{
		LuaTable metatable = GetMetaTable();
		assert(metatable.GetTypeOfValueAt("__call") == LuaType::function);
	}
	else
	{
		assert(type == LuaType::function);
	}
}
