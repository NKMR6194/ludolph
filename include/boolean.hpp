#pragma once

#include "object.hpp"
#include "class.hpp"

class LuryBoolean : public LuryObject {
	bool value;
public:
	LuryBoolean(bool value) : value(value) {
		setClass(LuryClass::getClass("Boolean"));
	}
	static void init() { LuryClass::createClass("Boolean"); }
	static inline bool classof(LuryBoolean const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Boolean";
	}
	bool isTrue() { return value; }
	bool isFalse() { return !value; }
	string to_s() { return value ? "true" : "false"; }
	LuryObject *equal(LuryObject *obj);
	LuryObject *notEqual(LuryObject *obj);
};
