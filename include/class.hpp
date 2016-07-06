#pragma once

#include "object.hpp"
#include "function.hpp"

using namespace std;

class LuryClass : public LuryObject {
private:
	string name;
	map<string, LuryFunction *> methods;
	// map<string, LuryObject *> class_variables;
	LuryClass *parent;

	static map<string, LuryClass *> class_objects;
public:
	LuryClass(string name) : name(name) {}
	void setMethod(string name, LuryFunction *function) { methods[name] = function; }
	LuryFunction *getMethod(string name) {
		LuryFunction *method = methods[name];
		if (method == NULL && parent != NULL) {
			method = parent->getMethod(name);
		}
		return method;
	}
	const string getName() { return name; }

	static void init();

	static void createClass(string name, string parent);

	static void createClass(string name) {
		createClass(name, "Object");
	}

	static LuryClass *getClass(string name) { return class_objects[name]; }
};
