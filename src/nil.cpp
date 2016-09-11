#include "../include/nil.hpp"

LuryNil *LuryNil::nil;
LuryClass *CLASS_OBJ_NIL;

LuryNil::LuryNil() : LuryObject(CLASS_OBJ_NIL) {}

void LuryNil::init() {
	CLASS_OBJ_NIL = LuryClass::createClass("Nil");
	nil = new LuryNil();
}
