#include "../include/boolean.hpp"

LuryObject* LuryBoolean::equal(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return new LuryBoolean(value == i->value);
	}
	throw "equal not impliment other object";
}

LuryObject* LuryBoolean::notEqual(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return new LuryBoolean(value != i->value);
	}
	throw "notEqual not impliment other object";
}
