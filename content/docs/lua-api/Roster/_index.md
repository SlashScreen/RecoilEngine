---
title: "Roster"
permalink: "docs/lua-api/types/Roster"
---
# class Roster





Roster

Contains data about a player

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaUnsyncedRead.cpp#L4236-L4248" target="_blank">source</a>]







---



## fields
---

### Roster.name
---
```lua
Roster.name : string
```










### Roster.playerID
---
```lua
Roster.playerID : integer
```










### Roster.teamID
---
```lua
Roster.teamID : integer
```










### Roster.allyTeamID
---
```lua
Roster.allyTeamID : integer
```










### Roster.spectator
---
```lua
Roster.spectator : boolean
```










### Roster.cpuUsage
---
```lua
Roster.cpuUsage : number
```



in order to find the progress, use: cpuUsage&0x1 if it's PC or BO, cpuUsage& 0xFE to get path res, (cpuUsage>>8)*1000 for the progress








### Roster.pingTime
---
```lua
Roster.pingTime : number
```



if -1, the player is pathfinding









