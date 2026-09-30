#include "graph_editor.h"
#include "godot_cpp/variant/variant.hpp"

void CGraphEditor::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &CGraphEditor::print_type);
	//godot::ClassDB::bind_method(D_METHOD("_ready"), &CGraphEditor::_ready);
}

void CGraphEditor::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}

void CGraphEditor::_ready() {
	print_line("Graph Editor is ready");
}
