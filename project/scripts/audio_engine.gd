extends Node
class_name AudioEngine

const SAMPLE_RATE := 44100.0
const BUFFER_SIZE := 512

@export var graph_editor: GraphEditor
@export var output_node: ModuleNode
@export var audio_player: AudioStreamPlayer

var buffer_cache : Dictionary = {}
var playback: AudioStreamGeneratorPlayback
var audio_generator: AudioStreamGenerator

func _ready() -> void:
	audio_generator = AudioStreamGenerator.new()
	audio_generator.mix_rate = SAMPLE_RATE
	audio_generator.buffer_length = 0.1
	
	audio_player.stream = audio_generator
	audio_player.play()
	playback = audio_player.get_stream_playback()

func _process(_delta):
	if playback == null:
		return
	while playback.get_frames_available() >= BUFFER_SIZE:
		var buffer := process_graph(BUFFER_SIZE)
		for sample in buffer:
			playback.push_frame(Vector2(sample, sample))

func process_graph(num_samples: int) -> PackedFloat32Array:
	buffer_cache.clear()
	return process_node(output_node, num_samples)

func process_node(node: ModuleNode, num_samples: int) -> PackedFloat32Array:
	if node == null:
		return PackedFloat32Array()
	if buffer_cache.has(node):
		return buffer_cache[node]
	
	var inputs := {}
	for port in node.input_count():
		var connection: Dictionary = graph_editor.find_connection_to(node, port)
		if connection.is_empty():
			continue
		var source : ModuleNode = graph_editor.get_node(NodePath(str(connection["from_node"])))
		inputs[port] = process_node(source, num_samples)
	var output : PackedFloat32Array = node.update_sound(num_samples, SAMPLE_RATE, inputs)
	buffer_cache[node] = output
	return output
