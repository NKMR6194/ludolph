#pragma once

#include "object.hpp"
#include "class.hpp"

class LuryInteger : public LuryObject {
	int value;
public:
	LuryInteger(int value) : value(value) {
		setClass(LuryClass::getClass("Integer"));
	}
	static void init() { LuryClass::createClass("Integer"); }
	static inline bool classof(LuryInteger const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Integer";
	}

	int getValue() { return value; }
	string to_s() { return to_string(value); }
	LuryObject *add(LuryObject *obj);
	LuryObject *sub(LuryObject *obj);
	LuryObject *mul(LuryObject *obj);
	LuryObject *div(LuryObject *obj);
	LuryObject *mod(LuryObject *obj);
	LuryObject *equal(LuryObject *obj);
	LuryObject *notEqual(LuryObject *obj);
	LuryObject *less(LuryObject *obj);
	LuryObject *lessOrEqual(LuryObject *obj);
	LuryObject *greater(LuryObject *obj);
	LuryObject *greaterOrEqual(LuryObject *obj);
};
