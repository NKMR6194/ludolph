#include "../include/ast.hpp"

ASTExit BinaryOpAST::eval(LuryContext *context) {
	ASTExit lhs_exit = lhs->eval(context);
	ASTExit rhs_exit = rhs->eval(context);
	LuryObject *lhs_obj = lhs_exit.getReturnValue();
	LuryObject *rhs_obj = rhs_exit.getReturnValue();
	LuryObject *obj;

	switch (op) {
	case OpAdd:
		obj = lhs_obj->add(rhs_obj);
		break;
	case OpSub:
		obj = lhs_obj->sub(rhs_obj);
		break;
	case OpMul:
		obj = lhs_obj->mul(rhs_obj);
		break;
	case OpDiv:
		obj = lhs_obj->div(rhs_obj);
		break;
	case OpMod:
		obj = lhs_obj->mod(rhs_obj);
		break;
	case OpEqual:
		obj = lhs_obj->equal(rhs_obj);
		break;
	case OpNotEqual:
		obj = lhs_obj->notEqual(rhs_obj);
		break;
	case OpLess:
		obj = lhs_obj->less(rhs_obj);
		break;
	case OpLessOrEqual:
		obj = lhs_obj->lessOrEqual(rhs_obj);
		break;
	case OpGreater:
		obj = lhs_obj->greater(rhs_obj);
		break;
	case OpGreaterOrEqual:
		obj = lhs_obj->greaterOrEqual(rhs_obj);
		break;
	case OpOr:
		obj = lhs_obj->luryOr(rhs_obj);
		break;
	default:
		throw "not support this operation";
	}

	ASTExit ast_exit(obj, NomalExit);
	return ast_exit;
}

ASTExit BinaryAssignAST::eval(LuryContext *context) {
	if (lhs->getValueID() != IdentifierID) {
		throw "lhs is not identifier";
	}

	IdentifierAST *ident = (IdentifierAST *)lhs;
	ASTExit rhs_exit = rhs->eval(context);
	LuryObject *obj, *ret;
	ret = rhs_exit.getReturnValue();
	switch (op) {
	case OpEqual:
		break;
	case OpAdd:
		obj = context->get(ident->getValue());
		ret = obj->add(ret);
		break;
	case OpSub:
		obj = context->get(ident->getValue());
		ret = obj->sub(ret);
		break;
	case OpMul:
		obj = context->get(ident->getValue());
		ret = obj->mul(ret);
		break;
	case OpDiv:
		obj = context->get(ident->getValue());
		ret = obj->div(ret);
		break;
	default:
		throw "not support operater";
	}
	context->set(ident->getValue(), ret);
	ASTExit ast_exit(ret, NomalExit);
	return ast_exit;
}

ASTExit IfStatementAST::eval(LuryContext *context) {
	if (condition == NULL) {
		throw "condition NULL";
	}

	ASTExit cond_exit = condition->eval(context);
	LuryObject *cond_obj = cond_exit.getReturnValue();
	if (!LuryBoolean::classof(cond_obj)) {
		throw "condition is not boolean";
	}

	LuryBoolean *bool_obj = (LuryBoolean *)cond_obj;
	if (bool_obj->isTrue()) {
		return then_stmt->eval(context);
	}
	else {
		if (else_stmt == NULL) {
			ASTExit ast_exit(new LuryNil(), NomalExit);
			return ast_exit;
		}
		else {
			return else_stmt->eval(context);
		}
	}
}

ASTExit CompoundAST::eval(LuryContext *context) {
	LuryObject *obj;
	ASTExit stmt_exit;
	for (auto stmt : list) {
		stmt_exit = stmt->eval(context);
		if (stmt_exit.getExitReason() != NomalExit) {
			break;
		}
	}
	return stmt_exit;
}

ASTExit IdentifierAST::eval(LuryContext *context) {
	LuryObject *obj = context->get(value);
	if (obj == NULL) {
		obj = (LuryObject *)context->getMethod(value);
	}
	ASTExit ast_exit(obj, NomalExit);
	return ast_exit;
}

ASTExit FunctionStatementAST::eval(LuryContext *context) {
	context->setMethod(name, new LuryFunction(params, proc));
	ASTExit ast_exit(new LuryBoolean(true), NomalExit);
	return ast_exit;
}

ASTExit ClassStatementAST::eval(LuryContext *context) {
	LuryClass *klass = new LuryClass(name);
	context->set(name, klass);
	suit->eval(context->copy(klass));
	return ASTExit(new LuryNil(), NomalExit);
}

ASTExit CreateInstanceAST::eval(LuryContext *context) {
	LuryClass *klass = (LuryClass *)context->get(name);
	LuryObject *obj = (klass->create_instance)();
	obj->setClass(klass);
	return ASTExit(obj, NomalExit);
}

ASTExit CallAST::eval(LuryContext *context) {
	ASTExit callee_exit = callee->eval(context);
	LuryObject *obj = callee_exit.getReturnValue();
	if (obj == NULL) {
		throw "NULL";
	}
	if (LuryFunction::classof(obj)) {
		LuryFunction *func = (LuryFunction *) obj;
		LuryContext *func_context = context->copy();
		AST *native_arg = args.front();
		switch (func->getFunctionType()) {
		case NativeFunc:
			func->eval(native_arg->eval(func_context).getReturnValue());
			return ASTExit(new LuryNil(), NomalExit);
		case Instruction:
			AST *proc = func->getProc();
			list<string> params = func->getParams();

			auto params_itr = params.begin();
			auto args_itr = args.begin();
			while (args_itr != args.end()) {
				ASTExit arg_exit = (*args_itr)->eval(context);
				func_context->set(*params_itr, arg_exit.getReturnValue());
				params_itr++;
				args_itr++;
			}

			return proc->eval(func_context);
		}
	}
	else if (LuryLambda::classof(obj)) {
		LuryLambda *func = (LuryLambda *) obj;
		LuryContext *func_context = context->copy();

		AST *proc = func->getProc();
		list<string> params = func->getParams();

		auto params_itr = params.begin();
		auto args_itr = args.begin();
		while (args_itr != args.end()) {
			ASTExit arg_exit = (*args_itr)->eval(context);
			func_context->set(*params_itr, arg_exit.getReturnValue());
			params_itr++;
			args_itr++;
		}

		return proc->eval(func_context);
	}

	throw "this object is not function";
}

ASTExit ReturnStatementAST::eval(LuryContext *context) {
	ASTExit expr_exit = expr->eval(context);
	ASTExit ast_exit(expr_exit.getReturnValue(), Return);
	return ast_exit;
}

ASTExit ContinueStatementAST::eval(LuryContext *context) {
	return ASTExit(new LuryNil(), Continue);
}

ASTExit BreakStatementAST::eval(LuryContext *context) {
	return ASTExit(new LuryNil(), Break);
}

ASTExit WhileStatementAST::eval(LuryContext *context) {
	ASTExit ast_exit(new LuryNil(), NomalExit);
	while (true) {
		ASTExit condition_exit = condition->eval(context);
		if (condition_exit.getReturnValue() == NULL) {
			cout << "condition NULL" << endl;
		}
		if (!LuryBoolean::classof(condition_exit.getReturnValue())) {
			throw "condition is not boolean";
		}
		LuryBoolean *cond = (LuryBoolean *)condition_exit.getReturnValue();
		if (cond->isFalse()) {
			if (else_stmt != NULL) {
				ast_exit = else_stmt->eval(context);
			}
			break;
		}
		ast_exit = stmt->eval(context);
		if (ast_exit.getExitReason() == Continue) {
			// ignore
		}
		else if (ast_exit.getExitReason() == Break) {
			ast_exit = ASTExit(new LuryNil(), NomalExit);
			break;
		}
		else if (ast_exit.getExitReason() != NomalExit) {
			break;
		}
	}
	return ast_exit;
}

ASTExit NotAST::eval(LuryContext *context) {
	ASTExit expr_exit = expr->eval(context);
	bool boolean = expr_exit.getReturnValue()->isTrue();
	return ASTExit(new LuryBoolean(!boolean), NomalExit);
}

#include <dlfcn.h>

ASTExit ImportAST::eval(LuryContext *context) {
	void (*init_func)(LuryContext *);
	string name = ident->getValue();
	string lib_path = "./ext/" + name + ".so";
	string func_name = "Init_" + name;
	void *handle = dlopen(lib_path.c_str(), RTLD_NOW);

	if (handle == 0) {
		throw dlerror();
	}

	dlerror();
	init_func = (void (*)(LuryContext *))dlsym(handle, func_name.c_str());
	char *error;
	if ((error = dlerror()) != NULL)  {
		std::cerr << error << std::endl;
		exit(1);
	}
	(init_func)(context);
	return ASTExit(new LuryBoolean(true), NomalExit);
}
