#include "node_connection_resource.h"

void NodeConnectionResource::_bind_methods() {

	BIND_ENUM_CONSTANT(WIRE);
	BIND_ENUM_CONSTANT(INT);
	BIND_ENUM_CONSTANT(FLOAT);
	BIND_ENUM_CONSTANT(ENUM);

	ClassDB::bind_method(D_METHOD("set_name", "value"),&NodeConnectionResource::set_name);
	ClassDB::bind_method(D_METHOD("get_name"),&NodeConnectionResource::get_name);
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"),"set_name","get_name");

	ClassDB::bind_method(D_METHOD("set_id", "value"),&NodeConnectionResource::set_id);
	ClassDB::bind_method(D_METHOD("get_id"),&NodeConnectionResource::get_id);
	ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "id"),"set_id","get_id");

	ClassDB::bind_method(D_METHOD("set_min_value", "value"),&NodeConnectionResource::set_min_value);
	ClassDB::bind_method(D_METHOD("get_min_value"),&NodeConnectionResource::get_min_value);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_value"),"set_min_value","get_min_value");

	ClassDB::bind_method(D_METHOD("set_max_value", "value"),&NodeConnectionResource::set_max_value);
	ClassDB::bind_method(D_METHOD("get_max_value"),&NodeConnectionResource::get_max_value);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_value"),"set_max_value","get_max_value");

	ClassDB::bind_method(D_METHOD("set_default_value", "value"),&NodeConnectionResource::set_default_value);
	ClassDB::bind_method(D_METHOD("get_default_value"),&NodeConnectionResource::get_default_value);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "default_value"),"set_default_value","get_default_value");

	ClassDB::bind_method(D_METHOD("set_options", "value"),&NodeConnectionResource::set_options);
	ClassDB::bind_method(D_METHOD("get_options"),&NodeConnectionResource::get_options);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_STRING_ARRAY, "options"),"set_options","get_options");

	ClassDB::bind_method(D_METHOD("set_input_type", "value"),&NodeConnectionResource::set_input_type);
	ClassDB::bind_method(D_METHOD("get_input_type"),&NodeConnectionResource::get_input_type);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "input_type"),"set_input_type","get_input_type");

	ClassDB::bind_method(D_METHOD("set_enable_left_port", "value"),&NodeConnectionResource::set_enable_left_port);
	ClassDB::bind_method(D_METHOD("get_enable_left_port"),&NodeConnectionResource::get_enable_left_port);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enable_left_port"),"set_enable_left_port","get_enable_left_port");

	ClassDB::bind_method(D_METHOD("set_type_left_port", "value"),&NodeConnectionResource::set_type_left_port);
	ClassDB::bind_method(D_METHOD("get_type_left_port"),&NodeConnectionResource::get_type_left_port);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_left_port"),"set_type_left_port","get_type_left_port");

	ClassDB::bind_method(D_METHOD("set_wire_color_left_port", "value"),&NodeConnectionResource::set_wire_color_left_port);
	ClassDB::bind_method(D_METHOD("get_wire_color_left_port"),&NodeConnectionResource::get_wire_color_left_port);
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "wire_color_left_port"),"set_wire_color_left_port","get_wire_color_left_port");

	ClassDB::bind_method(D_METHOD("set_enable_right_port", "value"),&NodeConnectionResource::set_enable_right_port);
	ClassDB::bind_method(D_METHOD("get_enable_right_port"),&NodeConnectionResource::get_enable_right_port);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enable_right_port"),"set_enable_right_port","get_enable_right_port");

	ClassDB::bind_method(D_METHOD("set_type_right_port", "value"),&NodeConnectionResource::set_type_right_port);
	ClassDB::bind_method(D_METHOD("get_type_right_port"),&NodeConnectionResource::get_type_right_port);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type_right_port"),"set_type_right_port","get_type_right_port");

	ClassDB::bind_method(D_METHOD("set_wire_color_right_port", "value"),&NodeConnectionResource::set_wire_color_right_port);
	ClassDB::bind_method(D_METHOD("get_wire_color_right_port"),&NodeConnectionResource::get_wire_color_right_port);
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "wire_color_right_port"),"set_wire_color_right_port","get_wire_color_right_port");

}

void NodeConnectionResource::set_name(const String & p_value) {
	name = p_value;
}

String NodeConnectionResource::get_name() const {
	return name;
}

void NodeConnectionResource::set_id(const StringName & p_value) {
	id = p_value;
}

StringName NodeConnectionResource::get_id() const {
	return id;
}

void NodeConnectionResource::set_min_value(float p_value) {
	min_value = p_value;
}

float NodeConnectionResource::get_min_value() const {
	return min_value;
}

void NodeConnectionResource::set_max_value(float p_value) {
	max_value = p_value;
}

float NodeConnectionResource::get_max_value() const {
	return max_value;
}

void NodeConnectionResource::set_default_value(float p_value) {
	default_value = p_value;
}

float NodeConnectionResource::get_default_value() const {
	return default_value;
}

void NodeConnectionResource::set_options(const PackedStringArray & p_value) {
	options = p_value;
}

PackedStringArray NodeConnectionResource::get_options() const {
	return options;
}

void NodeConnectionResource::set_input_type(int p_value) {
	input_type = p_value;
}

int NodeConnectionResource::get_input_type() const {
	return input_type;
}

void NodeConnectionResource::set_enable_left_port(bool p_value) {
	enable_left_port = p_value;
}

bool NodeConnectionResource::get_enable_left_port() const {
	return enable_left_port;
}

void NodeConnectionResource::set_type_left_port(int p_value) {
	type_left_port = p_value;
}

int NodeConnectionResource::get_type_left_port() const {
	return type_left_port;
}

void NodeConnectionResource::set_wire_color_left_port(const Color & p_value) {
	wire_color_left_port = p_value;
}

Color NodeConnectionResource::get_wire_color_left_port() const {
	return wire_color_left_port;
}

void NodeConnectionResource::set_enable_right_port(bool p_value) {
	enable_right_port = p_value;
}

bool NodeConnectionResource::get_enable_right_port() const {
	return enable_right_port;
}

void NodeConnectionResource::set_type_right_port(int p_value) {
	type_right_port = p_value;
}

int NodeConnectionResource::get_type_right_port() const {
	return type_right_port;
}

void NodeConnectionResource::set_wire_color_right_port(const Color p_value) {
	wire_color_right_port = p_value;
}

Color NodeConnectionResource::get_wire_color_right_port() const {
	return wire_color_right_port;
}

