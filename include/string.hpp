#pragma once

#include "include/object.hpp"
#include "include/class.hpp"

using namespace std;

extern LuryClass *CLASS_OBJ_STRING;

class LuryString : public LuryObject {
private:
	const string value;

public:
	LuryString(string value);

	static void init();
	string const getValue() { return value; }

	LuryObject *constructor(vector<LuryObject *> args);
	LuryObject *to_s(vector<LuryObject *> args);
};
