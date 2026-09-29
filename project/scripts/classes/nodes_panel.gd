extends NodesPanel

@export var graph: GraphEdit

var is_hovered = false
var buttons: Array[NodeButton]

var _from_node: StringName
var _from_port: int
var _to_node: StringName
var _to_port: int
@onready var panel_options_holder = $NodesPanel/GridContainer
@onready var panel: Control = $NodesPanel

func _ready() -> void:
	for button in panel_options_holder.get_children():
		buttons.append(button)
		button.pressed.connect(button_pressed.bind(button))
		button.mouse_entered.connect(_enter_panel)
		button.mouse_exited.connect(_exit_panel)
	panel.mouse_entered.connect(_enter_panel)
	panel.mouse_exited.connect(_exit_panel)

func _enter_panel():
	is_hovered = true
func _exit_panel():
	is_hovered = false

func set_position(position: Vector2):
	panel.position = position

func open():
	is_hovered = false
	visible = true
	panel.global_position = panel.get_global_mouse_position()

func close():
	_from_node = ""
	_from_port = -1
	_to_node = ""
	_to_port = -1
	visible = false

func button_pressed(button: NodeButton):
	var new_node : GraphNode = button.node_scene.instantiate()
	graph.add_child(new_node)
	new_node.position_offset = graph.get_global_mouse_position() - graph.global_position
	if _from_node != "" && _from_port != -1 && new_node.input_count() > 0:
		graph.connect_node(_from_node, _from_port, new_node.name, 0)
	if _to_node != "" && _to_port != -1 && new_node.output_count() > 0:
		graph.connect_node(new_node.name, 0, _to_node, _to_port)
	close()
