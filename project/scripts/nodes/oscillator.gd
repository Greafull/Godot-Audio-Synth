extends ModuleNode

var phase : float = 0.0

func update_sound(num_samples: int, sample_rate: float, _inputs: Dictionary) -> PackedFloat32Array:
	var output := PackedFloat32Array()
	output.resize(num_samples)
	var frequency: float = params[&"freq"]
	var amplitude: float = params[&"amp"]
	var phase_increment: float = frequency / sample_rate
	for i in num_samples:
		if phase >= 1.0:
			phase -= 1.0
		phase += phase_increment
		var wave = int(round(params[&"waveform"]))
		match wave:
			0:
				output[i] = sin(phase * TAU) * amplitude
			1:
				output[i] = amplitude if phase < 0.5 else -amplitude
			2:
				output[i] = (2.0 * phase - 1.0) * amplitude
			3:
				output[i] = randf() * amplitude
	return output
