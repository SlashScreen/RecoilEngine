#ifndef SOLLUACONTEXT_H
#define SOLLUACONTEXT_H

#include <RmlUi/Core/Context.h>

#include <sol2/sol.hpp>

namespace Rml::SolLua
{
    class SolLuaContext : public ::Rml::Context
    {
    public:
        void SetEnvironment(sol::state_view *p_state);
        const sol::state_view *GetEnvironment();

    private:
        sol::state_view *env;
    };
}

#endif
