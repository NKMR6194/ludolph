#pragma once

#include "object.hpp"

class LuryString : public LuryObject {
	std::string value;
public:
	LuryString(std::string value) : value(value) {
		setClass(LuryClass::getClass("String"));
	}
	static void init() { LuryClass::createClass("String"); }
};
