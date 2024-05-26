@tool
extends Node

var plyloader = PLYLoader.new()
var element_names : PackedStringArray = [""]
var property_names : Array = [""]
var properties : Array = []
var loaded_file := false
var loaded_elements := false
var loaded_property_names := false
var loaded_properties := false

var gsplat_property_names : PackedStringArray = [
	"x","y","z",
	"opacity",
	"scale_1", "scale_2",
	"rot_0", "rot_1", "rot_2", "rot_3"
	]
	

@export_global_file() var ply_file_path : String  :
	set(value):
		ply_file_path=value

@export var load_file = false : 
	set(value): 
		load_file = false
		loaded_file = plyloader.load_ply(ply_file_path)
		print("loaded file: " + str(loaded_file))
		load_file = loaded_file
		
		
@export var get_element_names = false : 
	set(value): 
		if !loaded_file:
			return
		
		element_names = plyloader.get_element_names()
		#print(element_names)
		
		loaded_elements = true
		get_element_names = loaded_elements

@export var get_property_names = false : 
	set(value): 
		if !loaded_file:
			return
		
		
		property_names = []
		
		for i in element_names.size():
			property_names.append([])
			var prop_names :PackedStringArray = plyloader.get_property_names(element_names[i])
			for j in prop_names.size():
				property_names[i].append(prop_names[j])
		#print(property_names)
		loaded_property_names = true
		get_property_names = loaded_property_names

		
@export var get_properties = false : 
	set(value): 
		if !loaded_file:
			return
			
		properties = []
		for i in element_names.size():
			properties.append([])
			print(property_names[i].size())
			for j in property_names[i].size():
				properties[i].append([])
				var element_name :String = element_names[i]
				var property_name : String = property_names[i][j]
				var p : Array = plyloader.get_property(element_name,property_name)
				print("e_name["+str(i)+"]: ",element_names[i],
				"  p_name["+str(j)+"]: ", 
				property_names[i][j], 
				"  # of properties: ", 
				p.size())
				for k in p:
					properties[i][j].append(k)
				#print("element: ", properties[i], "  p_name: ", property_name[j], "  # of properties: ", properties[i][j].size())

	
		loaded_properties = true
		get_properties = loaded_properties
		
@export var test = false : 
	set(value): 
		if !loaded_file:
			return
		test = false
		var v_positions := PackedVector3Array([])
		for i in properties[0][0].size():
			var x: float= properties[0][0][i]
			var y: float= properties[0][1][i]
			var z: float= properties[0][2][i]
			v_positions.append(Vector3(x,y,z))
			if i < 100:
				print("["+str(i)+"]",x, y,z)
			
		var xyz = Vector3(properties[0][1])

