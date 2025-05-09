---
title: "Heading"
url: "docs/lua-api/types/Heading"
---
# alias Heading
---



```lua
(alias) Heading = integer
```




Integer in range `[-32768, 32767]` that represents a 2D (xz plane) unit
orientation.

```
                  F(N=2) = H(-32768 / 32767)

                         ^
                         |
                         |
 F(W=3) = H(-16384)  <---o--->  F(E=1) = H(16384)
                         |
                         |
                         v

                  F(S=0) = H(0)
```

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaSyncedCtrl.cpp#L3970-L3988" target="_blank">source</a>]
