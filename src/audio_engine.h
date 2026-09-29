#pragma once

#include <godot_cpp/classes/node.hpp>
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

namespace godot {

class CAudioEngine : public Node {
	GDCLASS(CAudioEngine, Node)

private:
	bool is_noob = true;

protected:
	static void _bind_methods();

public:
	double amplitude;
	void set_amplitude(const double p_amplitude);
	double get_amplitude() const;

	CAudioEngine();
	~CAudioEngine() override;

	void _ready() override;
};

}
