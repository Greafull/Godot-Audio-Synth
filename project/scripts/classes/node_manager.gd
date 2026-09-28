extends GraphEdit
class_name GraphEditor

@onready var nodes_panel: NodesPanel = $"../../NodesPanel"

func _on_connection_request(from_node, from_port, to_node, to_port) -> void:
	for connection in get_connection_list():
		if connection.to_node == to_node && connection.to_port == to_port:
			disconnect_node(connection.from_node, connection.from_port, connection.to_node, connection.to_port)
	connect_node(from_node, from_port, to_node, to_port)

func delete_selected_nodes():
	for graph_node in get_children():
		if !graph_node is GraphNode: continue
		if graph_node.selected && !graph_node is Output:
			graph_node.queue_free()

func find_connection_to(node: ModuleNode, port: int) -> Dictionary:
	for connection in get_connection_list():
		if connection["to_node"] == node.name && connection["to_port"] == port:
			return connection
	return {}

func delete_nearby_connections():
	var connection = get_closest_connection_at_point(get_global_mouse_position() - global_position, 10.0)
	if connection.is_empty(): return
	
	disconnect_node(
		connection["from_node"],
		connection["from_port"],
		connection["to_node"],
		connection["to_port"]
	)

func _on_disconnection_request(from_node: StringName, from_port: int, to_node: StringName, to_port: int) -> void:
	disconnect_node(from_node, from_port, to_node, to_port)

func is_input_connected(node: StringName, port: int) -> bool:
	for connection in get_connection_list():
		if connection.to_node == node && connection.to_port == port:
			return true
	return false

func _on_connection_to_empty(from_node: StringName, from_port: int, _release_position: Vector2) -> void:
	nodes_panel.open()
	nodes_panel._from_node = from_node
	nodes_panel._from_port = from_port

func _on_connection_from_empty(from_node: StringName, from_port: int, _release_position: Vector2) -> void:
	if !is_input_connected(from_node, from_port):
		nodes_panel.open()
		nodes_panel._to_node = from_node
		nodes_panel._to_port = from_port
