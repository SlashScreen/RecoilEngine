---
title: "Engine"
permalink: "docs/lua-api/globals/Engine"
---
# global Engine


Engine specific information.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Lua/LuaConstEngine.cpp#L28-L43" target="_blank">source</a>]







---



## fields
---

### Engine.version
---
```lua
Engine.version : string
```



"Major.Minor.PatchSet" for releases, "Major.Minor.PatchSet-CommitNum-gHash branch" otherwise








### Engine.versionFull
---
```lua
Engine.versionFull : string
```



"Major.Minor.PatchSet" for releases, "Major.Minor.PatchSet-CommitNum-gHash branch" otherwise. Will also include (buildFlags), if there're any.








### Engine.versionMajor
---
```lua
Engine.versionMajor : string
```



Major part of the named release version








### Engine.versionMinor
---
```lua
Engine.versionMinor : string
```



Minor part of the named release version








### Engine.versionPatchSet
---
```lua
Engine.versionPatchSet : string
```



Build number of the named release version








### Engine.commitsNumber
---
```lua
Engine.commitsNumber : string
```



Number of commits after the latest named release, non-zero indicates a "dev" build








### Engine.buildFlags
---
```lua
Engine.buildFlags : string
```



Gets additional engine buildflags, e.g. "Debug" or "Sync-Debug"








### Engine.featureSupport
---
```lua
Engine.featureSupport : FeatureSupport {
    NegativeGetUnitCurrentCommand: boolean,
    hasExitOnlyYardmaps: boolean,
    rmlUiApiVersion: integer,
    noAutoShowMetal: boolean,
    maxPiecesPerModel: integer,
    gunshipCruiseAltitudeMultiplier: number,
    noRefundForConstructionDecay: boolean,
    noRefundForFactoryCancel: boolean,
    noOffsetForFeatureID: boolean,
}
```



Table containing various engine features as keys; use for cross-version compat








### Engine.wordSize
---
```lua
Engine.wordSize : number
```



Indicates the build type always 64 these days








### Engine.gameSpeed
---
```lua
Engine.gameSpeed : number
```



Number of simulation gameframes per second








### Engine.textColorCodes
---
```lua
Engine.textColorCodes : TextColorCode {
    Color: string,
    ColorAndOutline: string,
    Reset: string,
}
```



Table containing keys that represent the color code operations during font rendering









