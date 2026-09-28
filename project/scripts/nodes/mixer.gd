extends ModuleNode

var mixer_input : NodeConnectionResource = preload("uid://cjcterd7byiwa")
var num_inputs : int = 0

func _ready() -> void:
	super._ready()
	for i in range(0, 2):
		_add_input()

func _on_parameter_changed(value: float, id: StringName):
	super._on_parameter_changed(value, id)
	if id != &"num_inputs": return
	while int(round(value)) != num_inputs:
		if int(round(value)) > num_inputs:
			_add_input()
		else:
			_remove_input()

func update_sound(num_samples: int, _sample_rate: float, inputs: Dictionary) -> PackedFloat32Array:
	var output := PackedFloat32Array()
	output.resize(num_samples)
	if inputs.is_empty(): return output
	
	for input in inputs.values():
		if input.size() != num_samples:
			push_warning("Mixer input has wrong buffer size.")
			continue
		for i in num_samples:
			output[i] += input[i]
	if params[&"gain"] != 1.0:
		for i in num_samples:
			output[i] *= params[&"gain"]
	return output

func _add_input() -> void:
	var new_input = mixer_input.duplicate()
	new_input.id = new_input.id + str(num_inputs)
	num_inputs += 1
	connections.append(new_input)
	update_last_node()

func update_last_node():
	var connection = connections[connections.size() - 1]
	_spawn_label(connection.name, self)
	set_slot(connections.size() - 1, connection.enable_left_port, connection.type_left_port, connection.wire_color_left_port, connection.enable_right_port, connection.type_right_port, connection.wire_color_right_port)

func _remove_input() -> void:
	if num_inputs <= 2: return
	num_inputs -= 1
	connections.remove_at(connections.size() - 1)
	clear_slot(-1)
	remove_child(get_child(-1))
