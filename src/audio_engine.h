#pragma once

#include <godot_cpp/classes/node.hpp>
#include "godot_cpp/classes/audio_stream_generator.hpp"
#include "godot_cpp/classes/audio_stream_generator_playback.hpp"
#include "godot_cpp/classes/audio_stream_player.hpp"
#include "godot_cpp/classes/graph_edit.hpp"
#include "godot_cpp/variant/packed_float32_array.hpp"
#include "graph_editor.h"
//#include "module_node.h"

namespace godot {

class CAudioEngine : public Node {
	GDCLASS(CAudioEngine, Node)

private:
	//ModuleNode output_node;
	CGraphEditor *graph_editor;
	AudioStreamPlayer *audio_player;
	HashMap<Node, PackedFloat32Array> buffer_cache;
	AudioStreamGeneratorPlayback *playback;
	AudioStreamGenerator *audio_generator;


protected:
	static void _bind_methods();

public:
	CAudioEngine();
	~CAudioEngine() override;

	void _ready() override;
	CGraphEditor *get_graph();
	void set_graph(CGraphEditor *graph);
};

}
