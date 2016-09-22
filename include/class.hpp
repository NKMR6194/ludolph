#pragma once

#include <map>
#include <string>

#include "object.hpp"

using namespace std;

class LuryClass : public LuryObject {
private:
	LuryClass(string name);

	const string name;
	LuryClass *parent;
	map<string, LuryMethod *> methods;

	static map<string, LuryClass *> class_objects;

public:

	LuryMethod *getMethod(string name);
	void setMethod(string name, LuryMethod *method);
	void setClassMethod(string name, LuryMethod *method);
	inline const string getName() { return name; }

	static void init();
	static LuryClass *createClass(string name, LuryClass *parent);
	static LuryClass *createClass(string name);
	static LuryClass *getClass(string name);
};

extern LuryClass *CLASS_OBJ_OBJECT;
extern LuryClass *CLASS_OBJ_CLASS;
