#pragma once
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/color.hpp>

using namespace godot;

class NodeConnectionResource : public Resource {
	GDCLASS(NodeConnectionResource, Resource);

public:
	enum InputType {
		WIRE,
		INT,
		FLOAT,
		ENUM,
	};

private:
	String name;
	StringName id;
	float min_value = 0.0f;
	float max_value = 1.0f;
	float default_value = 0.0f;
	PackedStringArray options;
	int input_type = WIRE;
	bool enable_left_port = true;
	int type_left_port = 0;
	Color wire_color_left_port = Color(0, 0, 1, 1);
	bool enable_right_port = false;
	int type_right_port = 0;
	Color wire_color_right_port = Color(0, 0, 1, 1);

protected:
	static void _bind_methods();

public:
	void set_name(const String & p_value);
	String get_name() const;

	void set_id(const StringName & p_value);
	StringName get_id() const;

	void set_min_value(float p_value);
	float get_min_value() const;

	void set_max_value(float p_value);
	float get_max_value() const;

	void set_default_value(float p_value);
	float get_default_value() const;

	void set_options(const PackedStringArray & p_value);
	PackedStringArray get_options() const;

	void set_input_type(int p_value);
	int get_input_type() const;

	void set_enable_left_port(bool p_value);
	bool get_enable_left_port() const;

	void set_type_left_port(int p_value);
	int get_type_left_port() const;

	void set_wire_color_left_port(const Color & p_value);
	Color get_wire_color_left_port() const;

	void set_enable_right_port(bool p_value);
	bool get_enable_right_port() const;

	void set_type_right_port(int p_value);
	int get_type_right_port() const;

	void set_wire_color_right_port(const Color p_value);
	Color get_wire_color_right_port() const;

};

VARIANT_ENUM_CAST(NodeConnectionResource::InputType);
