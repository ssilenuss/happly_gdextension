#include "ply_loader.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "happly.h"

using namespace godot;

void PLYLoader::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_element_names"), &PLYLoader::get_element_names);
  ClassDB::bind_method(D_METHOD("get_property_names","_element"), &PLYLoader::get_property_names);
  ClassDB::bind_method(D_METHOD("get_property","_element", "_property"), &PLYLoader::get_property);
  ClassDB::bind_method(D_METHOD("load_ply", "_file_name"), &PLYLoader::load_ply);
}


PLYLoader::PLYLoader() {
	// Initialize any variables here.
}

PLYLoader::~PLYLoader() {
	// Add your cleanup here.
}

bool PLYLoader::load_ply(String _file_name){
  file_name = (_file_name.utf8().get_data());
  UtilityFunctions::print("loaded file: " + _file_name);
  return true;
}

PackedStringArray PLYLoader::get_property_names(String _element){
  happly::PLYData plyIn(file_name);
  std::string element_name = (_element.utf8().get_data());
  std::vector<std::string> property_names =plyIn.getElement(element_name).getPropertyNames();

  PackedStringArray p = PackedStringArray();
  for(std::vector<std::string>::iterator it = property_names.begin(); it != property_names.end(); ++it) {
    std::string property_name = *it;
    String g_property_name = property_name.c_str();
    p.append(g_property_name);
  }
  return p;
}

PackedStringArray PLYLoader::get_element_names(){
  happly::PLYData plyIn(file_name);
  elements = plyIn.getElementNames();

  PackedStringArray e = PackedStringArray();
  for(std::vector<std::string>::iterator it = elements.begin(); it != elements.end(); ++it) {
    std::string element = *it;
    String g_element = element.c_str();
    e.append(g_element);
  }

  return e;
}

PackedFloat64Array PLYLoader::get_property(String _element, String _property){
  //convert String to st::string
  std::string property(_property.utf8().get_data());
  std::string element(_element.utf8().get_data());
  happly::PLYData plyIn(file_name);

  std::vector<double> v_prop = plyIn.getElement(element).getProperty<double>(property); 

  PackedFloat64Array p = PackedFloat64Array();
  for(std::vector<double>::iterator it = v_prop.begin(); it != v_prop.end(); ++it) {
    double value = *it;
    p.append(value);
  }
  
  return p;

}