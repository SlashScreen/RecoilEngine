#include "SolLuaContext.h"

namespace Rml::SolLua
{
    void SolLuaContext::SetEnvironment(sol::state_view *p_state)
    {
        env = p_state;
    }

    const sol::state_view *SolLuaContext::GetEnvironment()
    {
        return env;
    }
}
