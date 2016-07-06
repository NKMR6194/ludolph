#include "../include/function.hpp"
#include "../include/class.hpp"

void LuryFunction::init() {
	LuryClass::createClass("Function");
}

LuryFunction::LuryFunction (std::list<string> params, AST *proc)
	: func_type(Instruction), params(params), proc(proc) {
	setClass(LuryClass::getClass("Function"));
}

LuryFunction::LuryFunction (function<void(LuryObject *)> nfunc)
	: func_type(NativeFunc), nfunc(nfunc) {
	setClass(LuryClass::getClass("Function"));
}
