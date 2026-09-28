extends ModuleNode
class_name Output

func update_sound(
	num_samples: int, _sample_rate: float, inputs: Dictionary) -> PackedFloat32Array:
	if !inputs.has(0):
		var silence := PackedFloat32Array()
		silence.resize(num_samples)
		return silence
	return inputs[0]
