#pragma once

#include "godot_cpp/classes/canvas_layer.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class NodesPanel : public CanvasLayer {
	GDCLASS(NodesPanel, CanvasLayer)

protected:
	static void _bind_methods();

public:
	NodesPanel() = default;
	~NodesPanel() override = default;

	void print_type(const Variant &p_variant) const;
};
