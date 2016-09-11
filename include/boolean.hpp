#pragma once

#include "object.hpp"
#include "class.hpp"

extern LuryClass *CLASS_OBJ_BOOL;

class LuryBoolean : public LuryObject {
private:
	const bool value;
	static LuryBoolean *obj_true;
	static LuryBoolean *obj_false;

	LuryBoolean(bool value);

public:
	static void init();
	static inline bool classof(LuryBoolean const*) { return true; }
	static inline bool classof(LuryObject *object) {
		return object->getClass() == CLASS_OBJ_BOOL;
	}
	static inline LuryBoolean *getInstance(bool value) {
		return value ? obj_true : obj_false;
	}

	inline bool isTrue() { return value; }
	inline bool isFalse() { return !value; }
	inline string to_s() { return value ? "true" : "false"; }
	LuryObject *equal(LuryObject *obj);
	LuryObject *notEqual(LuryObject *obj);
};
