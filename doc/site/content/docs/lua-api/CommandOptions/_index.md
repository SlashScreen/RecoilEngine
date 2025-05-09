---
title: "CommandOptions"
permalink: "docs/lua-api/types/CommandOptions"
---
# class CommandOptions





Full command options object for reading from a `Command`.

Note that this has extra fields `internal` and `coded` that are not supported
when creating a command from Lua.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaUtils.cpp#L931-L945" target="_blank">source</a>]







---



## fields
---

### CommandOptions.coded
---
```lua
CommandOptions.coded : (CommandOptionBit|integer)
```



Bitmask of command options.








### CommandOptions.alt
---
```lua
CommandOptions.alt : boolean
```



Alt key pressed.








### CommandOptions.ctrl
---
```lua
CommandOptions.ctrl : boolean
```



Ctrl key pressed.








### CommandOptions.shift
---
```lua
CommandOptions.shift : boolean
```



Shift key pressed.








### CommandOptions.right
---
```lua
CommandOptions.right : boolean
```



Right mouse key pressed.








### CommandOptions.meta
---
```lua
CommandOptions.meta : boolean
```



Meta key (space) pressed.








### CommandOptions.internal
---
```lua
CommandOptions.internal : boolean
```











