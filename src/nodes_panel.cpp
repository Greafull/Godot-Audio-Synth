#include "nodes_panel.h"

void NodesPanel::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &NodesPanel::print_type);
}

void NodesPanel::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}
