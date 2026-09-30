#pragma once

#include <godot_cpp/classes/node.hpp>
#include "godot_cpp/classes/audio_stream_generator.hpp"
#include "godot_cpp/classes/audio_stream_playback.hpp"
#include "godot_cpp/classes/audio_stream_player.hpp"
#include "godot_cpp/classes/graph_edit.hpp"
#include "graph_editor.h"
//#include "module_node.h"

namespace godot {

class CAudioEngine : public Node {
	GDCLASS(CAudioEngine, Node)

private:
	//ModuleNode *output_node = nullptr;
	CGraphEditor *graph_editor = nullptr;
	AudioStreamPlayer *audio_player = nullptr;

	//HashMap<Node, PackedFloat32Array> buffer_cache;
	Ref<AudioStreamPlayback> playback;
	Ref<AudioStreamGenerator> audio_generator;


protected:
	static void _bind_methods();

public:
	CAudioEngine();
	~CAudioEngine() override;

	void _ready() override;
	CGraphEditor *get_graph();
	void set_graph(CGraphEditor *graph);

	AudioStreamPlayer *get_audio_player();
	void set_audio_player(AudioStreamPlayer *audio_player);
};

}
