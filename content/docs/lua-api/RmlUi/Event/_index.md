---
title: "Event"
permalink: "docs/lua-api/types/Event"
---
# class Event



- namespace: RmlUi



[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Event.cpp#L107-L116" target="_blank">source</a>]







---



## fields
---

### Event.current_element
---
```lua
Event.current_element : RmlUi.Element {
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










### Event.type
---
```lua
Event.type : string
```










### Event.parameters
---
```lua
Event.parameters : RmlUi.EventParametersProxy
```










### Event.event_phase
---
```lua
Event.event_phase : RmlUi.RmlEventPhase
```










### Event.interruptible
---
```lua
Event.interruptible : boolean
```










### Event.propogating
---
```lua
Event.propogating : boolean
```










### Event.immediate_propogating
---
```lua
Event.immediate_propogating : boolean
```











