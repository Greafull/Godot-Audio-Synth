extends ModuleNode

var phase : float = 0.0

func update_sound(num_samples: int, sample_rate: float, _inputs: Dictionary) -> PackedFloat32Array:
	var output := PackedFloat32Array()
	output.resize(num_samples)
	var frequency: float = params[&"fund_freq"]
	var amplitude: float = params[&"amp"]
	var phase_increment: float = frequency / sample_rate
	for i in num_samples:
		if phase >= 1.0:
			phase -= 1.0
		phase += phase_increment
		var note = sin(phase * TAU) * amplitude
		for overtone in params[&"overtones"]:
			var harmonic : int = overtone + 1
			note += sin(TAU * harmonic * phase) * amplitude
		output[i] = note
	return output
