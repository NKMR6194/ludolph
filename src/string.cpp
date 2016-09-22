#include "include/string.hpp"
#include "include/function.hpp"

LuryClass *CLASS_OBJ_STRING;

LuryString::LuryString(string value) :
	LuryObject(CLASS_OBJ_STRING), value(value)
{}

void LuryString::init() {
	CLASS_OBJ_STRING = LuryClass::createClass("String");

	CLASS_OBJ_STRING->setClassMethod("this", new LuryObjMethod<LuryString>(&LuryString::constructor));
	CLASS_OBJ_STRING->setMethod("to_s", new LuryObjMethod<LuryString>(&LuryString::to_s));
}

LuryObject *LuryString::constructor(vector<LuryObject *> args) {
	return new LuryString("");
}

LuryObject *LuryString::to_s(vector<LuryObject *> args) {
	return this;
}
