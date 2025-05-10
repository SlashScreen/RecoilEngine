---
title: "SaveImageOptions"
permalink: "docs/lua-api/types/SaveImageOptions"
---
# class SaveImageOptions





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaOpenGL.cpp#L6342-L6348" target="_blank">source</a>]







---



## fields
---

### SaveImageOptions.alpha
---
```lua
SaveImageOptions.alpha : boolean
```



(Default: `false`)








### SaveImageOptions.yflip
---
```lua
SaveImageOptions.yflip : boolean
```



(Default: `true`)








### SaveImageOptions.grayscale16bit
---
```lua
SaveImageOptions.grayscale16bit : boolean
```



(Default: `false`)








### SaveImageOptions.readbuffer
---
```lua
SaveImageOptions.readbuffer : GL {
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



(Default: current read buffer)









