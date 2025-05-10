---
title: "DrawFlag"
url: "docs/lua-api/types/DrawFlag"
---
# alias DrawFlag
---



```lua
(alias) DrawFlag = (0|1|2|4|8|16|32|128)
    | 0 -- No Draw
    | 1 -- Opaque Pass
    | 2 -- Alpha Pass
    | 4 -- Reflection Pass
    | 8 -- Refraction Pass
    | 16 -- Shadow pass - Opaque Objects
    | 32 -- Shadow pass - Transparent Objects
    | 128 -- Icon - Possibly Radar Icons

```




Drawing Flags

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaUnsyncedRead.cpp#L2110-L2122" target="_blank">source</a>]
