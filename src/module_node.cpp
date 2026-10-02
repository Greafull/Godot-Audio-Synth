#include "module_node.h"
#include "godot_cpp/variant/variant.hpp"
#include "resources/node_connection_resource.h"

void CModuleNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("input_count"), &CModuleNode::input_count);
}

CModuleNode::CModuleNode() {
	
}

int CModuleNode::input_count() const {
	int i = 0;
	for (Ref<NodeConnectionResource> connection: connections) {
		if (connection->get_enable_left_port()) {
			i++;
		}
	}
	return i;
}

void CModuleNode::_ready() {
	print_line("module node is ready");
}
