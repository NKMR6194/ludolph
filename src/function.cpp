#include "../include/function.hpp"
#include "../include/class.hpp"
#include "../include/context.hpp"
#include "../include/ast.hpp"
#include "../include/ast_exit.hpp"

LuryFunction::LuryFunction (list<string> params, AST *proc) :
	LuryObject(CLASS_OBJ_FUNCTION),
	func_type(Instruction),
	params(params),
	proc(proc)
{}

LuryFunction::LuryFunction (nfunction nfunc) :
	LuryObject(CLASS_OBJ_FUNCTION), func_type(NativeFunc), nfunc(nfunc)
{}

LuryFunction::~LuryFunction() {
	if (proc != NULL) {
		delete proc;
	}
}

bool LuryFunction::classof(LuryObject *object) {
	return object->getClass() == CLASS_OBJ_FUNCTION;
}

ASTExit LuryFunction::eval(LuryContext context, list<LuryObject *> args) {
	auto itr_arg = args.begin();
	auto itr_param = params.begin();

	switch (func_type) {
	case Instruction:
		while (itr_arg != args.end()) {
			context.set(*itr_param, *itr_arg);
			itr_arg++;
			itr_param++;
		}
		return proc->eval(&context);
	case NativeFunc:
		LuryObject *ret = nfunc(context.getClass(), args);
		return ASTExit(ret, NomalExit);
	}
}

void LuryFunction::init() {
	CLASS_OBJ_FUNCTION = LuryClass::createClass("Function");
}
