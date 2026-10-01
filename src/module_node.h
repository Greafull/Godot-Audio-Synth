#pragma once

#include "godot_cpp/classes/graph_node.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class CModuleNode : public GraphNode {
	GDCLASS(CModuleNode, GraphNode)

protected:
	static void _bind_methods();

public:
	CModuleNode() = default;
	~CModuleNode() override = default;
	void _ready() override;

	void print_type(const Variant &p_variant) const;
};
