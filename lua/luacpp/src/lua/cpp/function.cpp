#include <cassert>

#include "lua/cpp/coroutine.h"
#include "lua/cpp/table.h"
#include "lua/cpp/typetemplates.h"
#include "lua/cpp/function.h"

namespace lua {
namespace cpp
{

FunctionBase::FunctionBase(std::shared_ptr<lua_State> state, int index) : Reference(state, index)
{
	auto type = GetType();
    if (type != Value::function)
	{
        Table metatable = GetMetaTable();
        assert(metatable.GetTypeOfValueAt("__call") == Value::function);
	}
	else
	{
        assert(type == Value::function);
	}
}

}
}
