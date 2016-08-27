#include "../include/class.hpp"

map<string, LuryClass *> LuryClass::class_objects;

LuryObject *create_c() {
	return new LuryObject();
}

LuryClass::LuryClass(string name) : name(name) {
	create_instance = create_c;
}

void LuryClass::setMethod(string name, LuryFunction *function) {
	methods[name] = function;
}

LuryFunction *LuryClass::getMethod(string name) {
	LuryFunction *method = methods[name];
	if (method == NULL && parent != NULL) {
		method = parent->getMethod(name);
	}
	return method;
}

const string LuryClass::getName() { return name; }

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

void LuryClass::createClass(string name) {
	createClass(name, "Object");
}

LuryClass *LuryClass::getClass(string name) {
	return class_objects[name];
}
