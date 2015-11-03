#ifndef LUALIGHTUSERDATA_H
#define LUALIGHTUSERDATA_H

#include <cassert>
#include <memory>

#include "lua/cpp/reference.h"
#include "lua/cpp/value.h"
#include "lua/cpp/userdata.h"

namespace lua {
namespace cpp {

template <typename T>
class LightUserdata : public Reference
{
    T* pointer;

public:
    LightUserdata(std::shared_ptr<lua_State> state, int index) : Reference(state, index)
    {
        assert(GetType() == Value::userdata || GetType() == Value::lightuserdata);

        if (GetType() == Value::lightuserdata)
        {
            pointer = (T*)lua_touserdata(state.get(), index);
        }
        else if (GetType() == Value::userdata)
        {
            auto wrap = (typename Userdata<T>::UserdataWrapper*)lua_touserdata(state.get(), index);
            pointer = wrap->actualData;
        }
    }

    T* GetPointer() const
    {
        return pointer;
    }
};


}
}


#endif // LUALIGHTUSERDATA_H
