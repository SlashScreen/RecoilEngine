---
title: "ElementTabSet"
permalink: "docs/lua-api/types/ElementTabSet"
---
# class ElementTabSet


- inherits: 
```lua
RmlUi.Element {
    attributes: RmlUi.ElementAttributesProxy,
    child_nodes: RmlUi.ElementChildNodesProxy,
    class_name: string,
    client_height: integer,
    client_left: integer,
    client_top: integer,
    client_width: integer,
    first_child: RmlUi.Element?,
    id: string,
    inner_rml: string,
    last_child: RmlUi.Element?,
    next_sibling: RmlUi.Element?,
    ...
}
```


- namespace: RmlUi



[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementDerived.cpp#L57-L61" target="_blank">source</a>]







---

## methods
---

### ElementTabSet.SetPanel
---
```lua
function ElementTabSet.SetPanel(
  index: integer,
  rml: string
)
```





Sets the contents of a panel to the RML content rml. If index is out-of-bounds, a new panel will be added at the end.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementDerived.cpp#L63-L68" target="_blank">source</a>]








### ElementTabSet.SetTab
---
```lua
function ElementTabSet.SetTab(
  index: integer,
  rml: string
)
```





Sets the contents of a tab to the RML content rml. If index is out-of-bounds, a new tab will be added at the end.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementDerived.cpp#L70-L75" target="_blank">source</a>]








### ElementTabSet.RemoveTab
---
```lua
function ElementTabSet.RemoveTab(index: integer)
```





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementDerived.cpp#L77-L80" target="_blank">source</a>]











## fields
---

### ElementTabSet.active_tab
---
```lua
ElementTabSet.active_tab : integer
```










### ElementTabSet.num_tabs
---
```lua
ElementTabSet.num_tabs : integer
```











