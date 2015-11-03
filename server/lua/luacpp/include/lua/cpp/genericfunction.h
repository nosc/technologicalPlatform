#ifndef LUAGENERICFUNCTION_H
#define LUAGENERICFUNCTION_H

#include <functional>
#include "lua/cpp/functionbase.h"

namespace lua {
namespace cpp {

template<typename T>
std::shared_ptr<T> NoDestructor(T* obj)
{
    return std::shared_ptr<T>(obj, [](T*){});
}


}
}

#include "generalgenericfunctions.h"
#include "voidgenericfunctions.h"

#endif // LUAGENERICFUNCTION_H
