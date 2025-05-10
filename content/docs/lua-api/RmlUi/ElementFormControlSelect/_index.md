---
title: "ElementFormControlSelect"
permalink: "docs/lua-api/types/ElementFormControlSelect"
---
# class ElementFormControlSelect


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
}, RmlUi.ElementFormControl {
    disabled: boolean,
    name: string,
    value: string,
    submitted: boolean,
}
```


- namespace: RmlUi



[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementForm.cpp#L217-L220" target="_blank">source</a>]







---

## methods
---

### ElementFormControlSelect.Add
---
```lua
function ElementFormControlSelect.Add(
  element: RmlUi.Element,
  before: integer?
)
```





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementForm.cpp#L222-L226" target="_blank">source</a>]








### ElementFormControlSelect.Remove
---
```lua
function ElementFormControlSelect.Remove(index: integer)
```





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementForm.cpp#L228-L231" target="_blank">source</a>]








### ElementFormControlSelect.RemoveAll
---
```lua
function ElementFormControlSelect.RemoveAll()
```





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/ElementForm.cpp#L233-L235" target="_blank">source</a>]











## fields
---

### ElementFormControlSelect.options
---
```lua
ElementFormControlSelect.options : RmlUi.SelectOptionsProxy
```











