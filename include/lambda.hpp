#pragma once

#include "object.hpp"
#include "class.hpp"

class AST;

extern LuryClass *CLASS_OBJ_LAMBDA;

class LuryLambda : public LuryObject {
private:
	vector<string> params;
	AST *proc;

public:
	LuryLambda(vector<string> params, AST *proc);

	static void init();

	inline vector<string> getParams() { return params; }
	inline AST *getProc() { return proc; }
};
