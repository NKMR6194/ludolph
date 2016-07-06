#include "../include/class.hpp"

map<string, LuryClass *> LuryClass::class_objects;

void LuryClass::createClass(string name, string parent) {
	LuryClass *new_class = new LuryClass(name);
	new_class->setClass(class_objects["Class"]);
	new_class->parent = class_objects[parent];

	class_objects[name] = new_class;
}

void LuryClass::init() {
	LuryClass *object = new LuryClass("Object");
	LuryClass *klass = new LuryClass("Class");

	object->setClass(klass);
	object->parent = NULL;
	class_objects["Object"] = object;

	klass->setClass(klass);
	klass->parent = object;
	class_objects["Class"] = object;
}
