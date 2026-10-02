#pragma once

#include <godot_cpp/classes/node.hpp>
#include "godot_cpp/classes/audio_stream_generator.hpp"
#include "godot_cpp/classes/audio_stream_generator_playback.hpp"
#include "godot_cpp/classes/audio_stream_player.hpp"
#include "godot_cpp/classes/graph_edit.hpp"
#include "godot_cpp/variant/packed_float32_array.hpp"
#include "graph_editor.h"
#include "module_node.h"

using namespace godot;

class CAudioEngine : public Node {
	GDCLASS(CAudioEngine, Node)

private:
	CModuleNode *output_node = nullptr;
	CGraphEditor *graph_editor = nullptr;
	AudioStreamPlayer *audio_player = nullptr;

	//HashMap<Node, PackedFloat32Array> buffer_cache;
	Ref<AudioStreamGeneratorPlayback> playback;
	Ref<AudioStreamGenerator> audio_generator;


protected:
	static void _bind_methods();

public:
	CAudioEngine();
	~CAudioEngine() override;

	void _ready() override;
	void _process(double delta) override;

	PackedFloat32Array _process_graph(int num_samples);
	PackedFloat32Array _process_node(CModuleNode* node, int num_samples);

	CGraphEditor *get_graph();
	void set_graph(CGraphEditor *graph);

	AudioStreamPlayer *get_audio_player();
	void set_audio_player(AudioStreamPlayer *audio_player);

	CModuleNode *get_output_node();
	void set_output_node(CModuleNode *module_node);
};