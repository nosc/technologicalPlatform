#ifndef LUAUSERDATA_H
#define LUAUSERDATA_H

#include <cassert>
#include <functional>
#include "lua/cpp/value.h"
#include "lua/cpp/reference.h"


namespace lua {
namespace cpp
{

class Machine;
class Table;

template<typename TYPE>
class Userdata : public Reference
{
    TYPE* pointer;

public:
    Userdata(std::shared_ptr<lua_State> state, int index) :
      Reference(state, index)
    {
        assert(GetType() == Value::userdata);
        assert(typeid(TYPE*) == typeid(RetrieveData()));

        auto wrap = (UserdataWrapper*)lua_touserdata(state.get(), index);
        pointer = wrap->actualData;
    }

    template<typename OBJ>
    void Set(std::string key, const OBJ& value)
    {
        Table table = GetMetaTable();
        table.template Set<OBJ>(key, value);
    }

    template<typename OBJ>
    OBJ Get(std::string key) const
    {
        Table table = GetMetaTable();
        return table.template Get<OBJ>(key);
    }

    TYPE* GetPointer() const
    {
        return pointer;
    }

    TYPE* operator->() const { return pointer; }

#include "userdataforwards.h"

    struct UserdataWrapper
    {
        TYPE* actualData;
        std::function< void(TYPE*) >* destructor;
    };

    static int lua_userdata_finalizer(lua_State* state)
    {
        UserdataWrapper* wrap = (UserdataWrapper*)lua_touserdata(state, lua_upvalueindex(1));
        (*wrap->destructor)(wrap->actualData);
        delete(wrap->destructor);
        return 0;
    };

    TYPE* RetrieveData() const
    {
        PushToStack(state.get());
        UserdataWrapper* wrap = (UserdataWrapper*)lua_touserdata(state.get(), -1);
        lua_pop(state.get(), 1);
        return wrap->actualData;
    }

};

}
}


#endif // LUAUSERDATA_H
