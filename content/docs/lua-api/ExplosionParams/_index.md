---
title: "ExplosionParams"
permalink: "docs/lua-api/types/ExplosionParams"
---
# class ExplosionParams





Parameters for explosion.

Please note the explosion defaults to 1 damage regardless of what it's defined in the weaponDef.
The weapondefID is only used for visuals and for passing into callins like UnitDamaged.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaSyncedCtrl.cpp#L7031-L7050" target="_blank">source</a>]







---



## fields
---

### ExplosionParams.weaponDef
---
```lua
ExplosionParams.weaponDef : number
```










### ExplosionParams.owner
---
```lua
ExplosionParams.owner : number
```










### ExplosionParams.hitUnit
---
```lua
ExplosionParams.hitUnit : number
```










### ExplosionParams.hitFeature
---
```lua
ExplosionParams.hitFeature : number
```










### ExplosionParams.craterAreaOfEffect
---
```lua
ExplosionParams.craterAreaOfEffect : number
```










### ExplosionParams.damageAreaOfEffect
---
```lua
ExplosionParams.damageAreaOfEffect : number
```










### ExplosionParams.edgeEffectiveness
---
```lua
ExplosionParams.edgeEffectiveness : number
```










### ExplosionParams.explosionSpeed
---
```lua
ExplosionParams.explosionSpeed : number
```










### ExplosionParams.gfxMod
---
```lua
ExplosionParams.gfxMod : number
```










### ExplosionParams.impactOnly
---
```lua
ExplosionParams.impactOnly : boolean
```










### ExplosionParams.ignoreOwner
---
```lua
ExplosionParams.ignoreOwner : boolean
```










### ExplosionParams.damageGround
---
```lua
ExplosionParams.damageGround : boolean
```











