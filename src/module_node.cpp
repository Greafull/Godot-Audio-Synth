#include "module_node.h"
#include "godot_cpp/variant/variant.hpp"

void CModuleNode::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &CModuleNode::print_type);
}

void CModuleNode::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}

void CModuleNode::_ready() {
	print_line("module node is ready");
}
