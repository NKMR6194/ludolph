#include "include/function.hpp"
#include "include/class.hpp"
#include "include/ast.hpp"

LuryClass *CLASS_OBJ_FUNCTION;

void LuryMethod::init() {
	CLASS_OBJ_FUNCTION = LuryClass::createClass("Function");
}

ASTExit LuryUserMethod::call(LuryObject *self, vector<LuryObject *> args) {
	LuryContext context(self);

	auto arg_itr = begin(args);
	auto param_itr = begin(params);
	while (arg_itr != end(args)) {
		context.set(*param_itr, *arg_itr);
		arg_itr++;
		param_itr++;
	}

	return proc->eval(&context);
}
