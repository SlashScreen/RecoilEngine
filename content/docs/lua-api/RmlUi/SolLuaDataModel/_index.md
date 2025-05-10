---
title: "SolLuaDataModel"
permalink: "docs/lua-api/types/SolLuaDataModel"
---
# class SolLuaDataModel


- inherits: 
```lua
{ __GetTable: fun() -> T }
```


- namespace: RmlUi



Handle for your data model. It is a wrapper around the model table, marked as type T.
You can access fields by using normal indexing, but for the moment, the only keys that work are strings. Any index done this way will automatically trigger a rerender.
If you need to index any tables or subtables by anything not a string, you will need to use the underlying table, gotten with `__GetTable`. This will not trigger a rerender.
To trigger a rerender manually, use `_SetDirty`, passing in the name of the top-level entry in your model table that you edited.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/DataModel.cpp#L60-L66" target="_blank">source</a>]







---

## methods
---

### SolLuaDataModel.__SetDirty
---
```lua
function SolLuaDataModel.__SetDirty(property: string)
```





Set a table property dirty to trigger a rerender

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/DataModel.cpp#L68-L72" target="_blank">source</a>]











