#include "ply_loader.h"
#include <godot_cpp/core/class_db.hpp>
#include "happly.h"

using namespace godot;

void PLYLoader::_bind_methods() {
}

PLYLoader::PLYLoader() {
	// Initialize any variables here.
	time_passed = 0.0;
}

PLYLoader::~PLYLoader() {
	// Add your cleanup here.
}

void PLYLoader::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

}