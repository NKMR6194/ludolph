#pragma once

#include "object.hpp"
#include "class.hpp"

class LuryNil : public LuryObject {
public:
	LuryNil() {
		setClass(LuryClass::getClass("Nil"));
	}
	static void init() { LuryClass::createClass("Nil"); }
};
