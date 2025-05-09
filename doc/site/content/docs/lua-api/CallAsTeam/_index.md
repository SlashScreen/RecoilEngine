---
title: "CallAsTeam"
permalink: "docs/lua-api/globals/CallAsTeam"
---

# global CallAsTeam

---

```lua
function CallAsTeam(
  teamID: integer,
  func: fun(...),
  ...: any
) -> The any...
```
@param `teamID` - Team ID.

@param `func` - The function to call.

@param `...` - Arguments to pass to the function.


@return `The` - return values of the function.






Calls a function from given team's PoV. In particular this makes callouts obey that team's visibility rules.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaHandleSynced.cpp#L2333-L2340" target="_blank">source</a>]

