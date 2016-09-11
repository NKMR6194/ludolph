#pragma once

#include "object.hpp"
#include "class.hpp"

extern LuryClass *CLASS_OBJ_FLOAT;

class LuryFloating : public LuryObject {
private:
	const double value;

public:
	LuryFloating(double value);

	static void init();
	static inline bool classof(LuryFloating const*) { return true; }
	static inline bool classof(LuryObject *object) {
		return object->getClass() == CLASS_OBJ_FLOAT;
	}

	inline double getValue() { return value; }
	inline string to_s() { return to_string(value); }
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
