#pragma once

#include "godot_cpp/classes/graph_node.hpp"
#include "godot_cpp/classes/ref.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/templates/list.hpp"
#include "resources/node_connection_resource.h"

using namespace godot;

class CModuleNode : public GraphNode {
	GDCLASS(CModuleNode, GraphNode)

private:
	List<Ref<NodeConnectionResource>> connections; 

protected:
	static void _bind_methods();

public:
	CModuleNode();
	~CModuleNode() override = default;
	void _ready() override;

	int input_count() const;
};
