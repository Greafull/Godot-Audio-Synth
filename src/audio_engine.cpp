#include "audio_engine.h"
#include "godot_cpp/classes/audio_stream_generator.hpp"
#include "godot_cpp/classes/audio_stream_playback.hpp"
#include "godot_cpp/classes/audio_stream_player.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/classes/ref.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/packed_float32_array.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector2.hpp"
#include "module_node.h"

namespace godot {

const float SAMPLE_RATE = 44100.0;
const int BUFFER_SIZE = 512;

void CAudioEngine::_bind_methods() {

	ClassDB::bind_method(D_METHOD("set_graph", "graph"), &CAudioEngine::set_graph);
	ClassDB::bind_method(D_METHOD("get_graph"), &CAudioEngine::get_graph);
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "graph_editor",
		PROPERTY_HINT_NODE_TYPE, "CGraphEditor"),
		"set_graph", "get_graph"
	);
	ClassDB::bind_method(D_METHOD("set_audio_player", "audio_stream"), &CAudioEngine::set_audio_player);
	ClassDB::bind_method(D_METHOD("get_audio_player"), &CAudioEngine::get_audio_player);
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "audio_player",
		PROPERTY_HINT_NODE_TYPE, "AudioStreamPlayer"),
		"set_audio_player", "get_audio_player"
	);

	ClassDB::bind_method(D_METHOD("set_output_node", "module_node"), &CAudioEngine::set_output_node);
	ClassDB::bind_method(D_METHOD("get_output_node"), &CAudioEngine::get_output_node);
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "output_node",
		PROPERTY_HINT_NODE_TYPE, "CModuleNode"),
		"set_output_node", "get_output_node"
	);
}

CAudioEngine::CAudioEngine() {
}

CAudioEngine::~CAudioEngine() {
}

void CAudioEngine::_ready() {
	print_line("ready");
	audio_generator.instantiate();
	audio_generator->set_mix_rate(SAMPLE_RATE);
	audio_generator->set_buffer_length(0.1);

	audio_player->set_stream(audio_generator);
	audio_player->play();
	playback = audio_player->get_stream_playback();
}

void CAudioEngine::_process(double delta) {
	if (playback.is_null()) {
		print_line("null playback");
		return;
	}
	while (playback->get_frames_available() >= BUFFER_SIZE) {
		PackedFloat32Array buffer = _process_graph(BUFFER_SIZE);
		for (float sample : buffer) {
			playback->push_frame(Vector2(sample, sample));
		}
	}
}

PackedFloat32Array CAudioEngine::_process_graph(int num_samples) {
	return _process_node(output_node, num_samples);
}

PackedFloat32Array CAudioEngine::_process_node(CModuleNode* node, int num_samples) {
	PackedFloat32Array output = PackedFloat32Array();
	output.resize(num_samples);
	if (node == nullptr) return output;
	return output;
}

CGraphEditor *CAudioEngine::get_graph() {
	return graph_editor;
}

void CAudioEngine::set_graph(CGraphEditor *graph) {
	graph_editor = graph;
}

AudioStreamPlayer *CAudioEngine::get_audio_player() {
	return audio_player;
}

void CAudioEngine::set_audio_player(AudioStreamPlayer *audio_stream) {
	audio_player = audio_stream;
}

CModuleNode *CAudioEngine::get_output_node() {
	return output_node;
}

void CAudioEngine::set_output_node(CModuleNode *module_node) {
	output_node = module_node;
}

}
