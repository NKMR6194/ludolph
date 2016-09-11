#include "../include/boolean.hpp"

LuryClass *CLASS_OBJ_BOOL;
LuryBoolean *LuryBoolean::obj_true;
LuryBoolean *LuryBoolean::obj_false;

LuryBoolean::LuryBoolean(bool value) : LuryObject(CLASS_OBJ_BOOL), value(value) {}

void LuryBoolean::init() {
	CLASS_OBJ_BOOL = LuryClass::createClass("Boolean");
	obj_true = new LuryBoolean(true);
	obj_false = new LuryBoolean(false);
}

LuryObject* LuryBoolean::equal(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return LuryBoolean::getInstance(value == i->value);
	}
	throw "equal not impliment other object";
}

LuryObject* LuryBoolean::notEqual(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return LuryBoolean::getInstance(value != i->value);
	}
	throw "notEqual not impliment other object";
}
