---
title: "Element"
permalink: "docs/lua-api/types/Element"
---
# class Element



- namespace: RmlUi



Represents an element in the RmlUi document tree. This class cannot be constructed directly; use a Document object to instantiate elements. This is the foundational piece of the DOM.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L231-L267" target="_blank">source</a>]







---

## methods
---

### Element.AddEventListener
---
```lua
function Element.AddEventListener(
  event: string,
  listener: (function|string),
  in_capture_phase: boolean
)
```





Adds an event listener to the element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L269-L275" target="_blank">source</a>]








### Element.AppendChild
---
```lua
function Element.AppendChild(element: RmlUi.ElementPtr) ->  RmlUi.ElementPtr
```





Appends element as a child to this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L277-L282" target="_blank">source</a>]








### Element.Blur
---
```lua
function Element.Blur()
```





Removes input focus from this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L284-L287" target="_blank">source</a>]








### Element.Click
---
```lua
function Element.Click()
```





Fakes a click on this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L289-L292" target="_blank">source</a>]








### Element.DispatchEvent
---
```lua
function Element.DispatchEvent(
  event: string,
  parameters: table,
  interruptible: string
) ->  boolean
```





Dispatches an event to this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L294-L301" target="_blank">source</a>]








### Element.Focus
---
```lua
function Element.Focus()
```





Gives input focus to this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L303-L306" target="_blank">source</a>]








### Element.GetAttribute
---
```lua
function Element.GetAttribute(name: string) ->  any
```





Returns the value of the attribute named name. If no such attribute exists, the empty string will be returned.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L308-L313" target="_blank">source</a>]








### Element.GetElementById
---
```lua
function Element.GetElementById(id: string) ->  RmlUi.Element
```





Returns the descendant element with an id of id.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L315-L320" target="_blank">source</a>]








### Element.GetElementsByTagName
---
```lua
function Element.GetElementsByTagName(tag_name: string) ->  RmlUi.ElementPtr[]
```





Returns a list of all descendant elements with the tag of tag_name.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L322-L327" target="_blank">source</a>]








### Element.HasAttribute
---
```lua
function Element.HasAttribute(name: string) ->  boolean
```





Returns True if the element has a value for the attribute named name, False if not.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L329-L334" target="_blank">source</a>]








### Element.HasChildNodes
---
```lua
function Element.HasChildNodes() ->  boolean
```





Returns True if the element has at least one child node, false if not.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L336-L340" target="_blank">source</a>]








### Element.InsertBefore
---
```lua
function Element.InsertBefore(
  element: RmlUi.ElementPtr,
  adjacent_element: RmlUi.Element
) ->  RmlUi.ElementPtr
```





Inserts the element element as a child of this element, directly before adjacent_element in the list of children.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L342-L348" target="_blank">source</a>]








### Element.IsClassSet
---
```lua
function Element.IsClassSet(name: string) ->  boolean
```





Returns true if the class name is set on the element, false if not.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L350-L355" target="_blank">source</a>]








### Element.RemoveAttribute
---
```lua
function Element.RemoveAttribute(name: string)
```





Removes the attribute named name from the element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L357-L361" target="_blank">source</a>]








### Element.RemoveChild
---
```lua
function Element.RemoveChild(element: RmlUi.Element) ->  boolean
```





Removes the child element element from this element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L363-L368" target="_blank">source</a>]








### Element.ReplaceChild
---
```lua
function Element.ReplaceChild(
  inserted_element: RmlUi.ElementPtr,
  replaced_element: RmlUi.Element
) ->  boolean
```





Replaces the child element replaced_element with inserted_element in this element's list of children. If replaced_element is not a child of this element, inserted_element will be appended onto the list instead.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L370-L376" target="_blank">source</a>]








### Element.ScrollIntoView
---
```lua
function Element.ScrollIntoView(align_with_top: boolean)
```





Scrolls this element into view if its ancestors have hidden overflow.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L378-L382" target="_blank">source</a>]








### Element.SetAttribute
---
```lua
function Element.SetAttribute(
  name: string,
  value: string
)
```





Sets the value of the attribute named name to value.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L384-L389" target="_blank">source</a>]








### Element.SetClass
---
```lua
function Element.SetClass(
  name: string,
  value: boolean
)
```





Sets (if value is true) or clears (if value is false) the class name on the element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Element.cpp#L391-L396" target="_blank">source</a>]











## fields
---

### Element.attributes
---
```lua
Element.attributes : RmlUi.ElementAttributesProxy
```



Read-only. Proxy for accessing element attributes.








### Element.child_nodes
---
```lua
Element.child_nodes : RmlUi.ElementChildNodesProxy
```



Read-only. Proxy for accessing child nodes of the element.








### Element.class_name
---
```lua
Element.class_name : string
```



Gets or sets the class names assigned to the element.








### Element.client_height
---
```lua
Element.client_height : integer
```



Read-only. The inner height of the element in pixels, including padding but not the horizontal scrollbar height, border, or margin.








### Element.client_left
---
```lua
Element.client_left : integer
```



Read-only. The width of the left border of the element in pixels.








### Element.client_top
---
```lua
Element.client_top : integer
```



Read-only. The width of the top border of the element in pixels.








### Element.client_width
---
```lua
Element.client_width : integer
```



Read-only. The inner width of the element in pixels, including padding but not the vertical scrollbar width, border, or margin.








### Element.first_child
---
```lua
Element.first_child : RmlUi.Element?
```



Read-only. The first child element, or nil if there are no children.








### Element.id
---
```lua
Element.id : string
```



Gets or sets the unique identifier of the element.








### Element.inner_rml
---
```lua
Element.inner_rml : string
```



Gets or sets the inner RML (markup) content of the element.








### Element.last_child
---
```lua
Element.last_child : RmlUi.Element?
```



Read-only. The last child element, or nil if there are no children.








### Element.next_sibling
---
```lua
Element.next_sibling : RmlUi.Element?
```



Read-only. The next sibling element, or nil if there is none.








### Element.offset_height
---
```lua
Element.offset_height : integer
```



Read-only. The height of the element including vertical padding and borders, in pixels.








### Element.offset_left
---
```lua
Element.offset_left : integer
```



Read-only. The distance from the inner left edge of the offset parent, in pixels.








### Element.offset_parent
---
```lua
Element.offset_parent : RmlUi.Element {
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



Read-only. The closest positioned ancestor element.








### Element.offset_top
---
```lua
Element.offset_top : integer
```



Read-only. The distance from the inner top edge of the offset parent, in pixels.








### Element.offset_width
---
```lua
Element.offset_width : integer
```



Read-only. The width of the element including horizontal padding and borders, in pixels.








### Element.owner_document
---
```lua
Element.owner_document : RmlUi.Document {
    context: RmlUi.Context,
    title: string,
    url: string,
    modal: boolean,
    widget: table,
}
```



Read-only. The document that owns this element.








### Element.parent_node
---
```lua
Element.parent_node : RmlUi.Element?
```



Read-only. The parent node of this element, or nil if there is none.








### Element.previous_sibling
---
```lua
Element.previous_sibling : RmlUi.Element?
```



Read-only. The previous sibling element, or nil if there is none.








### Element.scroll_height
---
```lua
Element.scroll_height : integer
```



Read-only. The total height of the element's content, including content not visible on the screen due to overflow.








### Element.scroll_left
---
```lua
Element.scroll_left : integer
```



Gets or sets the number of pixels that the content of the element is scrolled from the left.








### Element.scroll_top
---
```lua
Element.scroll_top : integer
```



Gets or sets the number of pixels that the content of the element is scrolled from the top.








### Element.scroll_width
---
```lua
Element.scroll_width : integer
```



Read-only. The total width of the element's content, including content not visible on the screen due to overflow.








### Element.style
---
```lua
Element.style : RmlUi.ElementStyleProxy
```



Read-only. Proxy for accessing and modifying the element's style properties.








### Element.tag_name
---
```lua
Element.tag_name : string
```



Read-only. The tag name of the element.








### Element.address
---
```lua
Element.address : string
```



Read-only. The address of the element in the document tree.








### Element.absolute_left
---
```lua
Element.absolute_left : integer
```



Read-only. The absolute left position of the element relative to the document.








### Element.absolute_top
---
```lua
Element.absolute_top : integer
```



Read-only. The absolute top position of the element relative to the document.








### Element.baseline
---
```lua
Element.baseline : integer
```



Read-only. The baseline position of the element.








### Element.line_height
---
```lua
Element.line_height : integer
```



Read-only. The computed line height of the element.








### Element.visible
---
```lua
Element.visible : boolean
```



Read-only. True if the element is visible, false otherwise.








### Element.z_index
---
```lua
Element.z_index : integer
```



Read-only. The computed z-index of the element.









