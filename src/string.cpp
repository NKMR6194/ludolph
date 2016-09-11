#include "../include/string.hpp"

LuryClass *CLASS_OBJ_STRING;

LuryString::LuryString(string value) :
	LuryObject(CLASS_OBJ_STRING), value(value)
{}

void LuryString::init() {
	CLASS_OBJ_STRING = LuryClass::createClass("String");
}
