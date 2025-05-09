---
title: "VBOAttributeDef"
permalink: "docs/lua-api/types/VBOAttributeDef"
---
# class VBOAttributeDef





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaVBOImpl.cpp#L459-L494" target="_blank">source</a>]







---



## fields
---

### VBOAttributeDef.id
---
```lua
VBOAttributeDef.id : integer?
```



The location in the vertex shader layout e.g.: layout (location = 0) in vec2
aPos. optional attrib, specifies location in the vertex shader. If not
specified the implementation will increment the counter starting from 0.
There can be maximum 16 attributes (so id of 15 is max).








### VBOAttributeDef.name
---
```lua
VBOAttributeDef.name : string?
```



(Default: `attr#` where `#` is `id`)

The name for this VBO, only used for debugging.








### VBOAttributeDef.size
---
```lua
VBOAttributeDef.size : integer?
```



Defaults to to 4 for VBO. The number of floats that constitute 1 element in
this buffer. e.g. for the previous layout (location = 0) in vec2 aPos, it
would be size = 2.








### VBOAttributeDef.type
---
```lua
VBOAttributeDef.type : GL?
```



(Default: `GL.FLOAT`) The datatype of this element.

Accepts the following:
- `GL.BYTE`
- `GL.UNSIGNED_BYTE`
- `GL.SHORT`
- `GL.UNSIGNED_SHORT`
- `GL.INT`
- `GL.UNSIGNED_INT`
- `GL.FLOAT`








### VBOAttributeDef.normalized
---
```lua
VBOAttributeDef.normalized : boolean?
```



(Defaults: `false`)

It's possible to submit normals without normalizing them first, normalized
will make sure data is normalized.









