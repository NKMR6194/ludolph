#pragma once

#include "object.hpp"
#include "class.hpp"

class AST;

class LuryLambda : public LuryObject {
private:
	std::list<string> params;
	AST *proc;
public:
	LuryLambda(list<string> params, AST *proc) {};
	static void init() { LuryClass::createClass("Lambda"); }
	static inline bool classof(LuryFunction const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Lambda";
	}

	std::list<string> getParams() { return params; }
	AST *getProc() { return proc; }
};
