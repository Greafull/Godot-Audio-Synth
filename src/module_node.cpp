#include "module_node.h"
#include "godot_cpp/variant/variant.hpp"

void ModuleNode::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("print_type", "variant"), &ModuleNode::print_type);
	godot::ClassDB::bind_method(D_METHOD("_ready"), &ModuleNode::_ready);
}

void ModuleNode::print_type(const Variant &p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}

void ModuleNode::_ready() {
	print_line("module node is ready");
}
