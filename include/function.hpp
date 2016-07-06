#pragma once

#include <list>

#include "object.hpp"

class AST;

enum FunctionType {
	Instruction,
	NativeFunc
};

class LuryFunction : public LuryObject {
private:
	FunctionType func_type;
	std::list<string> params;
	AST *proc;
	function<void(LuryObject *)> nfunc;
public:
	LuryFunction(std::list<string> params, AST *proc);
	LuryFunction (function<void(LuryObject *)> nfunc);
	static void init();
	static inline bool classof(LuryFunction const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Function";
	}
	std::list<string> getParams() { return params; }
	AST *getProc() { return proc; }
	FunctionType getFunctionType() { return func_type; }

	void eval(LuryObject *obj) { return nfunc(obj); }
};
