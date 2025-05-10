---
title: "CreateRBOData"
permalink: "docs/lua-api/types/CreateRBOData"
---
# class CreateRBOData





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaRBOs.cpp#L150-L155" target="_blank">source</a>]







---



## fields
---

### CreateRBOData.target
---
```lua
CreateRBOData.target : GL {
    POINTS: integer,
    LINES: integer,
    LINE_LOOP: integer,
    LINE_STRIP: integer,
    TRIANGLES: integer,
    TRIANGLE_STRIP: integer,
    TRIANGLE_FAN: integer,
    QUADS: integer,
    QUAD_STRIP: integer,
    POLYGON: integer,
    LINE_STRIP_ADJACENCY: integer,
    LINES_ADJACENCY: integer,
    ...
}
```










### CreateRBOData.format
---
```lua
CreateRBOData.format : GL {
    POINTS: integer,
    LINES: integer,
    LINE_LOOP: integer,
    LINE_STRIP: integer,
    TRIANGLES: integer,
    TRIANGLE_STRIP: integer,
    TRIANGLE_FAN: integer,
    QUADS: integer,
    QUAD_STRIP: integer,
    POLYGON: integer,
    LINE_STRIP_ADJACENCY: integer,
    LINES_ADJACENCY: integer,
    ...
}
```










### CreateRBOData.samples
---
```lua
CreateRBOData.samples : number?
```



any number here will result in creation of multisampled RBO









