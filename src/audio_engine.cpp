#include "audio_engine.h"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/variant.hpp"

namespace godot {

const float SAMPLE_RATE = 44100.0;
const int BUFFER_SIZE = 512;

void CAudioEngine::_bind_methods() {
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "graph_editor",
		PROPERTY_HINT_NODE_TYPE, "CGraphEditor"),
		"set_graph", "get_graph"
	);
	ClassDB::bind_method(D_METHOD("set_graph", "graph"), &CAudioEngine::set_graph);
	ClassDB::bind_method(D_METHOD("get_graph"), &CAudioEngine::get_graph);

}

CAudioEngine::CAudioEngine() {
}

CAudioEngine::~CAudioEngine() {
	// Cleanup here.
}

void CAudioEngine::_ready() {
	print_line("ready");
}

CGraphEditor *CAudioEngine::get_graph() {
	return graph_editor;
}

void CAudioEngine::set_graph(CGraphEditor *graph) {
	graph_editor = graph;
}

}
