
namespace lua {
namespace cpp
{

template<typename TYPE>
template<typename RET>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)() )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET()>(std::bind(func, t));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0)>(std::bind(func, t, std::placeholders::_1));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)() )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET()>(std::bind(func, t));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0)>(std::bind(func, t, std::placeholders::_1));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7) )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}


template<typename TYPE>
template<typename RET>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)() const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET()>(std::bind(func, t));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0)>(std::bind(func, t, std::placeholders::_1));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
void Userdata<TYPE>::Bind(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)() const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET()>(std::bind(func, t));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0)>(std::bind(func, t, std::placeholders::_1));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}

template<typename TYPE>
template<typename RET, typename ARG0, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
void Userdata<TYPE>::BindYield(std::string name, RET(TYPE::*func)(ARG0, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7) const )
{
    using namespace std::placeholders;
    TYPE* t = RetrieveData();
    Machine lua(state);
    auto luaFunc = lua.CreateYieldingFunction<RET(ARG0,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7)>(std::bind(func, t, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8));
    Table table = GetMetaTable();
    table.Set(name, luaFunc);
}


}
}
