#ifndef LUALIGHTUSERDATA_H
#define LUALIGHTUSERDATA_H

#include <cassert>
#include <memory>
#include "lua/cpp/luareference.h"
#include "lua/cpp/luatype.h"
#include "lua/cpp/luauserdata.h"

template <typename T>
class LuaLightUserdata : public LuaReference
{
	T* pointer;

public:
	LuaLightUserdata(std::shared_ptr<lua_State> state, int index) : LuaReference(state, index)
	{
		assert(GetType() == LuaType::userdata || GetType() == LuaType::lightuserdata);

		if (GetType() == LuaType::lightuserdata)
		{
			pointer = (T*)lua_touserdata(state.get(), index);
		}
		else if (GetType() == LuaType::userdata)
		{
			auto wrap = (typename LuaUserdata<T>::UserdataWrapper*)lua_touserdata(state.get(), index);
			pointer = wrap->actualData;
		}
	}

	T* GetPointer() const
	{
		return pointer;
	}
};


#endif // LUALIGHTUSERDATA_H
