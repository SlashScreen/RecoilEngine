---
title: "Document"
permalink: "docs/lua-api/types/Document"
---
# class Document


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



Document derives from Element. Document has no constructor; it must be instantiated through a Context object instead, either by loading an external RML file or creating an empty document. It has the following functions and properties:

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L125-L133" target="_blank">source</a>]







---

## methods
---

### Document.Close
---
```lua
function Document.Close()
```





Hides and closes the document, destroying its contents.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L135-L138" target="_blank">source</a>]








### Document.CreateElement
---
```lua
function Document.CreateElement(tag_name: string) ->  RmlUi.ElementPtr
```





Instances an element with a tag of tag_name.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L140-L145" target="_blank">source</a>]








### Document.CreateTextNode
---
```lua
function Document.CreateTextNode(text: string) ->  RmlUi.ElementPtr
```





Instances a text element containing the string text.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L147-L152" target="_blank">source</a>]








### Document.Hide
---
```lua
function Document.Hide()
```





Hides the document.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L154-L157" target="_blank">source</a>]








### Document.PullToFront
---
```lua
function Document.PullToFront()
```





Pulls the document in front of other documents within its context with a similar z-index.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L159-L162" target="_blank">source</a>]








### Document.PushToBack
---
```lua
function Document.PushToBack()
```





Pushes the document behind other documents within its context with a similar z-index.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L164-L167" target="_blank">source</a>]








### Document.Show
---
```lua
function Document.Show(
  modal: RmlModalFlag?,
  focus: RmlFocusFlag?
)
```
@param `modal` - Defaults to Focus






Shows the document.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Document.cpp#L169-L174" target="_blank">source</a>]











## fields
---

### Document.context
---
```lua
Document.context : RmlUi.Context {
    dimensions: RmlUi.Vector2i,
    documents: RmlUi.Document[],
    focus_element: RmlUi.Element,
    hover_element: RmlUi.Element,
    name: string,
    root_element: RmlUi.Element,
    dp_ratio: number,
}
```










### Document.title
---
```lua
Document.title : string
```










### Document.url
---
```lua
Document.url : string
```










### Document.modal
---
```lua
Document.modal : boolean
```



is modal?








### Document.widget
---
```lua
Document.widget : table
```











