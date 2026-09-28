extends Control

@onready var nodes_panel : NodesPanel = $NodesPanel
@onready var graph: GraphEditor = $GraphWindow/GraphEdit

func _process(_delta: float) -> void:
	if Input.is_action_just_pressed("open_nodes_panel"):
		nodes_panel.open()
	if Input.is_action_just_pressed("select") && !nodes_panel.is_hovered:
		nodes_panel.close()
	if Input.is_action_just_pressed("delete"):
		graph.delete_selected_nodes()
		graph.delete_nearby_connections()
