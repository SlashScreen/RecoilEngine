---
title: "Menu"
permalink: "docs/lua-api/types/Menu"
---
# class Menu


- inherits: 
```lua
Callins
```




[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaMenu.cpp#L34-L37" target="_blank">source</a>]







---

## methods
---

### Menu.ActivateMenu
---
```lua
function Menu.ActivateMenu()
```





Called whenever LuaMenu is on with no game loaded.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaMenu.cpp#L372-L375" target="_blank">source</a>]








### Menu.ActivateGame
---
```lua
function Menu.ActivateGame()
```





Called whenever LuaMenu is on with a game loaded.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaMenu.cpp#L393-L396" target="_blank">source</a>]








### Menu.AllowDraw
---
```lua
function Menu.AllowDraw() -> allowDraw boolean
```





Enables Draw{Genesis,Screen,ScreenPost} callins if true is returned,
otherwise they are called once every 30 seconds. Only active when a game
isn't running.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaMenu.cpp#L413-L420" target="_blank">source</a>]











