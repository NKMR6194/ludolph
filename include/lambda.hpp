#pragma once

#include "object.hpp"
#include "class.hpp"

class AST;

extern LuryClass *CLASS_OBJ_LAMBDA;

class LuryLambda : public LuryObject {
private:
	std::list<string> params;
	AST *proc;

public:
	LuryLambda(list<string> params, AST *proc);

	static void init();
	static inline bool classof(LuryFunction const*) { return true; }
	static inline bool classof(LuryObject *object) {
		return object->getClass() == CLASS_OBJ_LAMBDA;
	}

	inline std::list<string> getParams() { return params; }
	inline AST *getProc() { return proc; }
};
