#ifndef PLYLOADER_REGISTER_TYPES_H
#define PLYLOADER_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_plyloader_module(ModuleInitializationLevel p_level);
void uninitialize_plyloader_module(ModuleInitializationLevel p_level);

#endif // PLYLOADER_REGISTER_TYPES_H