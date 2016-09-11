#pragma once

#include "object.hpp"
#include "class.hpp"

extern LuryClass *CLASS_OBJ_INT;

class LuryInteger : public LuryObject {
private:
	const int value;

public:
	LuryInteger(int value);

	static void init();
	static inline bool classof(LuryInteger const*) { return true; }
	static inline bool classof(LuryObject *object) {
		return object->getClass() == CLASS_OBJ_INT;
	}

	inline int getValue() { return value; }
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
