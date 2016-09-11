#pragma once

#include "object.hpp"
#include "class.hpp"

using namespace std;

extern LuryClass *CLASS_OBJ_STRING;

class LuryString : public LuryObject {
private:
	const string value;

public:
	LuryString(string value);

	static void init();
};
