---
title: "Context"
permalink: "docs/lua-api/types/Context"
---
# class Context



- namespace: RmlUi



Holds documents and a data model.
The Context class has no constructor; it must be instantiated through the CreateContext() function. It has the following functions and properties:

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L285-L296" target="_blank">source</a>]







---

## methods
---

### Context.AddEventListener
---
```lua
function Context.AddEventListener(
  event: string,
  script: RmlUi.Element,
  element_context: boolean,
  in_capture_phase: boolean
)
```





Adds the inline Lua script, script, as an event listener to the context. element_context is an optional Element; if it is not None, then the script will be executed as if it was bound to that element.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L298-L305" target="_blank">source</a>]








### Context.CreateDocument
---
```lua
function Context.CreateDocument(tag: string) ->  RmlUi.Document
```





Creates a new document with the tag name of tag.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L307-L312" target="_blank">source</a>]








### Context.LoadDocument
---
```lua
function Context.LoadDocument(document_path: string) ->  RmlUi.Document
```





Attempts to load a document from the RML file found at document_path. If successful, the document will be returned with a reference count of one.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L314-L319" target="_blank">source</a>]








### Context.Render
---
```lua
function Context.Render() ->  boolean
```





Renders the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L321-L325" target="_blank">source</a>]








### Context.UnloadAllDocuments
---
```lua
function Context.UnloadAllDocuments()
```





Closes all documents currently loaded with the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L327-L330" target="_blank">source</a>]








### Context.UnloadDocument
---
```lua
function Context.UnloadDocument(document: RmlUi.Document)
```





Unloads a specific document within the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L332-L336" target="_blank">source</a>]








### Context.Update
---
```lua
function Context.Update() ->  boolean
```





Updates the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L338-L342" target="_blank">source</a>]








### Context.OpenDataModel
---
```lua
function Context.OpenDataModel(
  name: string,
  model: T,
  widget: table
) ->  SolLuaDataModel<T>
```





Create a new data model from a base table `model` and register to the context. The model table is copied.
Note that `widget` does not actually have to be a widget; it can be any table. This table can be accessed in widgets like `<button class="mode-button" onclick="widget:SetCamMode()">Set Dolly Mode</button>`. Also note that your data model is inaccessible in `onx` properties.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L344-L353" target="_blank">source</a>]








### Context.UnloadAllDocuments
---
```lua
function Context.UnloadAllDocuments()
```





[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L355-L357" target="_blank">source</a>]








### Context.RemoveDataModel
---
```lua
function Context.RemoveDataModel(name: string)
```





Removes a data model from the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L359-L363" target="_blank">source</a>]








### Context.ProcessMouseMove
---
```lua
function Context.ProcessMouseMove(position: RmlUi.Vector2f) ->  boolean
```





Processes a mouse move event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L365-L370" target="_blank">source</a>]








### Context.ProcessMouseButtonDown
---
```lua
function Context.ProcessMouseButtonDown(
  button: RmlUi.MouseButton,
  key_modifier_state: integer
) ->  boolean
```





Processes a mouse button down event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L372-L378" target="_blank">source</a>]








### Context.ProcessMouseButtonUp
---
```lua
function Context.ProcessMouseButtonUp(
  button: RmlUi.MouseButton,
  key_modifier_state: integer
) ->  boolean
```





Processes a mouse button up event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L380-L386" target="_blank">source</a>]








### Context.ProcessMouseWheel
---
```lua
function Context.ProcessMouseWheel(
  delta: (RmlUi.Vector2f|number),
  key_modifier_state: integer
) ->  boolean
```





Processes a mouse wheel event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L388-L394" target="_blank">source</a>]








### Context.ProcessMouseLeave
---
```lua
function Context.ProcessMouseLeave() ->  boolean
```





Processes a mouse leave event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L396-L400" target="_blank">source</a>]








### Context.IsMouseInteracting
---
```lua
function Context.IsMouseInteracting() ->  boolean
```





Returns true if the mouse is currently interacting with the context, false if not.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L402-L406" target="_blank">source</a>]








### Context.ProcessKeyDown
---
```lua
function Context.ProcessKeyDown(
  key: RmlUi.key_identifier,
  key_modifier_state: integer
) ->  boolean
```





Processes a key down event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L408-L414" target="_blank">source</a>]








### Context.ProcessKeyUp
---
```lua
function Context.ProcessKeyUp(
  key: RmlUi.key_identifier,
  key_modifier_state: integer
) ->  boolean
```





Processes a key up event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L416-L422" target="_blank">source</a>]








### Context.ProcessTextInput
---
```lua
function Context.ProcessTextInput(text: string) ->  boolean
```





Processes a text input event.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L424-L429" target="_blank">source</a>]








### Context.EnableMouseCursor
---
```lua
function Context.EnableMouseCursor(enable: boolean)
```





Enables or disables the mouse cursor for the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L431-L435" target="_blank">source</a>]








### Context.ActivateTheme
---
```lua
function Context.ActivateTheme(
  theme_name: string,
  activate: boolean
)
```





Activates a theme for the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L437-L442" target="_blank">source</a>]








### Context.IsThemeActive
---
```lua
function Context.IsThemeActive(theme_name: string) ->  boolean
```





Returns true if the theme is active, false if not.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L444-L449" target="_blank">source</a>]








### Context.GetElementAtPoint
---
```lua
function Context.GetElementAtPoint(
  point: RmlUi.Vector2f,
  ignore: RmlUi.Element?
) ->  RmlUi.Element
```





Returns the element at the point specified by point.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L451-L457" target="_blank">source</a>]








### Context.PullDocumentToFront
---
```lua
function Context.PullDocumentToFront(document: RmlUi.Document)
```





Pulls the document to the front of the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L459-L463" target="_blank">source</a>]








### Context.PushDocumentToBack
---
```lua
function Context.PushDocumentToBack(document: RmlUi.Document)
```





Pushes the document to the back of the context.

[<a href="https://github.com/SlashScreen/RecoilEngine/blob/b16b1e4d2ec4d049d46e390398a33d9a3dd46f0c/rts/Rml/SolLua/bind/Context.cpp#L465-L469" target="_blank">source</a>]











## fields
---

### Context.dimensions
---
```lua
Context.dimensions : RmlUi.Vector2i {
    magnitude: number,
    x: integer,
    y: integer,
}
```










### Context.documents
---
```lua
Context.documents : RmlUi.Document[]
```










### Context.focus_element
---
```lua
Context.focus_element : RmlUi.Element {
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










### Context.hover_element
---
```lua
Context.hover_element : RmlUi.Element {
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










### Context.name
---
```lua
Context.name : string
```










### Context.root_element
---
```lua
Context.root_element : RmlUi.Element {
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










### Context.dp_ratio
---
```lua
Context.dp_ratio : number
```











