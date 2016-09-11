#pragma once

#include "object.hpp"
#include "class.hpp"

class LuryNil : public LuryObject {
private:
	LuryNil();

	static LuryNil *nil;

public:
	static void init();
	inline static LuryNil *getInstance() { return nil; }
};

extern LuryClass *CLASS_OBJ_NIL;
