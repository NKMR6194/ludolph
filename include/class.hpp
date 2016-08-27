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
	LuryClass(string name);
	LuryObject *(*create_instance)();
	void setMethod(string name, LuryFunction *function);
	LuryFunction *getMethod(string name);
	const string getName();

	static void init();

	static void createClass(string name, string parent);

	static void createClass(string name);

	static LuryClass *getClass(string name);
};
