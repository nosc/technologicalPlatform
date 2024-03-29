#ifndef LUAVOIDGENERICFUNCTIONS_H
#define LUAVOIDGENERICFUNCTIONS_H

namespace lua {
namespace cpp {

template<>
class GenericFunction<void()> : public FunctionBase
{
public:
    static const int parameters = 0;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke()
    {
        PushToStack(state.get());
        lua_call(state.get(), 0, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void()>* func = (std::function<void()>*)lua_touserdata(state, lua_upvalueindex(1));
        func->operator()();

        return 0;
    }
};

template<typename T1>
class GenericFunction<void(T1)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    static const int parameters = 1;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        lua_call(state.get(), 1, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1)>* func = (std::function<void(T1)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1);

        return 0;
    }
};

template<typename T1, typename T2>
class GenericFunction<void(T1,T2)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    static const int parameters = 2;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        lua_call(state.get(), 2, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2)>* func = (std::function<void(T1,T2)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2);

        return 0;
    }
};

template<typename T1, typename T2, typename T3>
class GenericFunction<void(T1,T2,T3)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    static const int parameters = 3;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        lua_call(state.get(), 3, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3)>* func = (std::function<void(T1,T2,T3)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3);

        return 0;
    }
};

template<typename T1, typename T2, typename T3, typename T4>
class GenericFunction<void(T1,T2,T3,T4)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    typedef T4 arg4type;
    static const int parameters = 4;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        pusher<arg4type>::push(state, arg4);
        lua_call(state.get(), 4, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3,T4)>* func = (std::function<void(T1,T2,T3,T4)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg4type arg4 = popper<arg4type>::pop(NoDestructor(state));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3, arg4);

        return 0;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5>
class GenericFunction<void(T1,T2,T3,T4,T5)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    typedef T4 arg4type;
    typedef T5 arg5type;
    static const int parameters = 5;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4, arg5type arg5)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        pusher<arg4type>::push(state, arg4);
        pusher<arg5type>::push(state, arg5);
        lua_call(state.get(), 5, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3,T4,T5)>* func = (std::function<void(T1,T2,T3,T4,T5)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg5type arg5 = popper<arg5type>::pop(NoDestructor(state));
        arg4type arg4 = popper<arg4type>::pop(NoDestructor(state));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3, arg4, arg5);

        return 0;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class GenericFunction<void(T1,T2,T3,T4,T5,T6)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    typedef T4 arg4type;
    typedef T5 arg5type;
    typedef T6 arg6type;
    static const int parameters = 6;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4, arg5type arg5, arg6type arg6)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        pusher<arg4type>::push(state, arg4);
        pusher<arg5type>::push(state, arg5);
        pusher<arg6type>::push(state, arg6);
        lua_call(state.get(), 6, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3,T4,T5,T6)>* func = (std::function<void(T1,T2,T3,T4,T5,T6)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg6type arg6 = popper<arg6type>::pop(NoDestructor(state));
        arg5type arg5 = popper<arg5type>::pop(NoDestructor(state));
        arg4type arg4 = popper<arg4type>::pop(NoDestructor(state));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3, arg4, arg5, arg6);

        return 0;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class GenericFunction<void(T1,T2,T3,T4,T5,T6,T7)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    typedef T4 arg4type;
    typedef T5 arg5type;
    typedef T6 arg6type;
    typedef T7 arg7type;
    static const int parameters = 7;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4, arg5type arg5, arg6type arg6, arg7type arg7)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        pusher<arg4type>::push(state, arg4);
        pusher<arg5type>::push(state, arg5);
        pusher<arg6type>::push(state, arg6);
        pusher<arg7type>::push(state, arg7);
        lua_call(state.get(), 7, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3,T4,T5,T6,T7)>* func = (std::function<void(T1,T2,T3,T4,T5,T6,T7)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg7type arg7 = popper<arg7type>::pop(NoDestructor(state));
        arg6type arg6 = popper<arg6type>::pop(NoDestructor(state));
        arg5type arg5 = popper<arg5type>::pop(NoDestructor(state));
        arg4type arg4 = popper<arg4type>::pop(NoDestructor(state));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

        return 0;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class GenericFunction<void(T1,T2,T3,T4,T5,T6,T7,T8)> : public FunctionBase
{
public:

    typedef T1 arg1type;
    typedef T2 arg2type;
    typedef T3 arg3type;
    typedef T4 arg4type;
    typedef T5 arg5type;
    typedef T6 arg6type;
    typedef T7 arg7type;
    typedef T8 arg8type;
    static const int parameters = 8;

    GenericFunction(std::shared_ptr<lua_State> state, int index) : FunctionBase(state, index)
    {
    }

    void Invoke(arg1type arg1, arg2type arg2, arg3type arg3, arg4type arg4, arg5type arg5, arg6type arg6, arg7type arg7, arg8type arg8)
    {
        PushToStack(state.get());
        pusher<arg1type>::push(state, arg1);
        pusher<arg2type>::push(state, arg2);
        pusher<arg3type>::push(state, arg3);
        pusher<arg4type>::push(state, arg4);
        pusher<arg5type>::push(state, arg5);
        pusher<arg6type>::push(state, arg6);
        pusher<arg7type>::push(state, arg7);
        pusher<arg8type>::push(state, arg8);
        lua_call(state.get(), 8, 1);
        // return void
    }

    static int staticFunction(lua_State* state)
    {
        std::function<void(T1,T2,T3,T4,T5,T6,T7,T8)>* func = (std::function<void(T1,T2,T3,T4,T5,T6,T7,T8)>*)lua_touserdata(state, lua_upvalueindex(1));
        arg8type arg8 = popper<arg8type>::pop(NoDestructor(state));
        arg7type arg7 = popper<arg7type>::pop(NoDestructor(state));
        arg6type arg6 = popper<arg6type>::pop(NoDestructor(state));
        arg5type arg5 = popper<arg5type>::pop(NoDestructor(state));
        arg4type arg4 = popper<arg4type>::pop(NoDestructor(state));
        arg3type arg3 = popper<arg3type>::pop(NoDestructor(state));
        arg2type arg2 = popper<arg2type>::pop(NoDestructor(state));
        arg1type arg1 = popper<arg1type>::pop(NoDestructor(state));
        func->operator()(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);

        return 0;
    }
};


}
}

#endif // LUAVOIDGENERICFUNCTIONS_H
