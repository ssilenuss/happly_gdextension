#ifndef PLYLOADER_H
#define PLYLOADER_H

#include <godot_cpp/classes/node.hpp>
#include "happly.h"

namespace godot {

class PLYLoader : public Node {
	GDCLASS(PLYLoader, Node)

private:
	std::string file_name;
	//happly::PLYData * data;
	std::vector<std::string> elements;

protected:
	static void _bind_methods();

public:
	PLYLoader();
	~PLYLoader();

	bool load_ply(String _file_name);
	PackedStringArray get_element_names();
	PackedStringArray get_property_names(String _element);

	PackedFloat64Array get_property(String _element, String _property);
};

}

#endif