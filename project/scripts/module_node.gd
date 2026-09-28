extends GraphNode
class_name ModuleNode

@export var connections : Array[NodeConnectionResource]
var params := {}
signal param_changed(id: StringName, value: float)

func update_sound(_num_samples: int, _sample_rate: float, _inputs: Dictionary) -> PackedFloat32Array:
	return PackedFloat32Array()

func _ready() -> void:
	build_node()

func build_node():
	for i in connections.size():
		var connection : NodeConnectionResource = connections[i]
		match connection.input_type:
			NodeConnectionResource.InputType.WIRE:
				_spawn_label(connection.name, self)
			NodeConnectionResource.InputType.INT, NodeConnectionResource.InputType.FLOAT:
				var box : VBoxContainer = VBoxContainer.new()
				add_child(box)
				_spawn_label(connection.name, box)
				var spin : SpinBox = SpinBox.new()
				if connection.input_type == connection.InputType.INT:
					spin.step = 1.0
				else:
					spin.step = 0.001
				spin.min_value = connection.min_value
				spin.max_value = connection.max_value
				spin.value = connection.default_value
				params[connection.id] = spin.value
				box.add_child(spin)
				spin.value_changed.connect(_on_parameter_changed.bind(connection.id))
			NodeConnectionResource.InputType.ENUM:
				var box : VBoxContainer = VBoxContainer.new()
				add_child(box)
				_spawn_label(connection.name, box)
				var options_button : OptionButton = OptionButton.new()
				for option in connection.options:
					options_button.add_item(option)
				options_button.selected = int(connection.default_value)
				box.add_child(options_button)
				params[connection.id] = options_button.selected
				options_button.item_selected.connect(_on_enum_changed.bind(connection.id))
		set_slot(i, connection.enable_left_port, connection.type_left_port, connection.wire_color_left_port, connection.enable_right_port, connection.type_right_port, connection.wire_color_right_port)

func _on_parameter_changed(value: float, id: StringName):
	params[id] = value
	param_changed.emit(id, value)

func _on_enum_changed(index: int, id: StringName) -> void:
	_on_parameter_changed(index, id)

func _spawn_label(label_name: String, parent: Node):
	var label = Label.new()
	label.text = label_name
	parent.add_child(label)

func input_row(port: int) -> NodeConnectionResource:
	var i := 0
	for connection in connections:
		if connection.enable_left_port:
			if i == port: return connection
			i += 1
	return null

func output_row(port: int) -> NodeConnectionResource:
	var i := 0
	for connection in connections:
		if connection.enable_right_port:
			if i == port: return connection
			i += 1
	return null

func input_count() -> int:
	var i := 0
	for connection in connections:
		if connection.enable_left_port:
			i += 1
	return i

func output_count() -> int:
	var i := 0
	for connection in connections:
		if connection.enable_right_port:
			i += 1
	return i
