#pragma once

#include "object.hpp"
#include "function.hpp"

using namespace std;

class LuryClass : public LuryObject {
private:
	LuryClass(string name);

	const string name;
	LuryClass *parent;

	static map<string, LuryClass *> class_objects;

public:

	LuryObject *getMethod(string name);
	inline const string getName() { return name; }

	static void init();
	static LuryClass *createClass(string name, LuryClass *parent);
	static LuryClass *createClass(string name);
	static LuryClass *getClass(string name);
};

extern LuryClass *CLASS_OBJ_OBJECT;
extern LuryClass *CLASS_OBJ_CLASS;
extern LuryClass *CLASS_OBJ_FUNCTION;
