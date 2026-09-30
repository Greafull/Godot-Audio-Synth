#pragma once

#include "godot_cpp/classes/graph_edit.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class CGraphEditor : public GraphEdit {
	GDCLASS(CGraphEditor, GraphEdit)

protected:
	static void _bind_methods();

public:
	CGraphEditor() = default;
	~CGraphEditor() override = default;
	void _ready() override;

	void print_type(const Variant &p_variant) const;
};
