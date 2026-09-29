#include "audio_engine.h"
#include "godot_cpp/core/object.hpp"

namespace godot {

const float SAMPLE_RATE = 44100.0;
const int BUFFER_SIZE = 512;

void CAudioEngine::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_amplitude"), &CAudioEngine::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &CAudioEngine::set_amplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");
}

CAudioEngine::CAudioEngine() {
	is_noob = true;
	amplitude = 10.0;
}

CAudioEngine::~CAudioEngine() {
	// Cleanup here.
}

void CAudioEngine::_ready() {
	print_line("ready");
}

void CAudioEngine::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double CAudioEngine::get_amplitude() const {
	return amplitude;
}

}
