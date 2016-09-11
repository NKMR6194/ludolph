#pragma once

#include <list>

#include "object.hpp"

using namespace std;

typedef function<LuryObject *(LuryObject *, list<LuryObject *>)> nfunction;

class AST;
class LuryContext;

enum FunctionType {
	Instruction,
	NativeFunc
};

class LuryFunction : public LuryObject {
private:
	FunctionType func_type;
	list<string> params;
	AST *proc;
	nfunction nfunc;

public:
	LuryFunction(list<string> params, AST *proc);
	LuryFunction(nfunction nfunc);
	~LuryFunction();
	static inline bool classof(LuryFunction const*) { return true; }
	static bool classof(LuryObject *object);

	ASTExit eval(LuryContext context, list<LuryObject *> args);
	inline list<string> getParams() { return params; }
	inline AST *getProc() { return proc; }
	inline FunctionType getFunctionType() { return func_type; }

	static void init();
};
