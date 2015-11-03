#ifndef LUACOROUTINE_H
#define LUACOROUTINE_H

#include <cassert>
#include <string>
#include "lua/cpp/reference.h"

namespace lua {
namespace cpp
{

class Coroutine : public Reference
{
public:
    Coroutine(std::shared_ptr<lua_State> state, int index);

    // run a script
    std::string RunScript(std::string script);

    // resume the yielded coroutine
    std::string Resume();

    bool CanResume() const;
};

}
}


#endif // LUACOROUTINE_H
