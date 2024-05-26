#ifndef PLYLOADER_H
#define PLYLOADER_H

#include <godot_cpp/classes/node.hpp>
#include "happly.h"

namespace godot {

class PLYLoader : public Node {
	GDCLASS(PLYLoader, Node)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	PLYLoader();
	~PLYLoader();

	void _process(double delta) override;
};

}

#endif