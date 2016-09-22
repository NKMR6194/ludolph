#include "../include/ast.hpp"

ASTExit BinaryOpAST::eval(LuryContext *context) {
	ASTExit lhs_exit = lhs->eval(context);
	ASTExit rhs_exit = rhs->eval(context);
	LuryObject *lhs_obj = lhs_exit.getReturnValue();
	LuryObject *rhs_obj = rhs_exit.getReturnValue();

	switch (op) {
	case OpAdd:
		return lhs_obj->send("+", {rhs_obj});
	case OpSub:
		return lhs_obj->send("-", {rhs_obj});
	case OpMul:
		return lhs_obj->send("*", {rhs_obj});
	case OpDiv:
		return lhs_obj->send("/", {rhs_obj});
	case OpMod:
		return lhs_obj->send("%", {rhs_obj});
	case OpEqual:
		return lhs_obj->send("==", {rhs_obj});
	case OpNotEqual:
		return lhs_obj->send("!=", {rhs_obj});
	case OpLess:
		return lhs_obj->send("<", {rhs_obj});
	case OpLessOrEqual:
		return lhs_obj->send("<=", {rhs_obj});
	case OpGreater:
		return lhs_obj->send(">", {rhs_obj});
	case OpGreaterOrEqual:
		return lhs_obj->send(">=", {rhs_obj});
	// case OpOr:
	// 	obj = lhs_obj->luryOr(rhs_obj);
	// 	break;
	default:
		throw "not support this operation";
	}
}

ASTExit BinaryAssignAST::eval(LuryContext *context) {
	throw "not impliment BinaryAssignAST::eval";

	// if (lhs->getValueID() != IdentifierID) {
	// 	throw "lhs is not identifier";
	// }

	// IdentifierAST *ident = (IdentifierAST *)lhs;
	// ASTExit rhs_exit = rhs->eval(context);
	// LuryObject *obj, *ret;
	// ret = rhs_exit.getReturnValue();
	// switch (op) {
	// case OpEqual:
	// 	break;
	// case OpAdd:
	// 	obj = context->get(ident->getValue());
	// 	ret = obj->add(ret);
	// 	break;
	// case OpSub:
	// 	obj = context->get(ident->getValue());
	// 	ret = obj->sub(ret);
	// 	break;
	// case OpMul:
	// 	obj = context->get(ident->getValue());
	// 	ret = obj->mul(ret);
	// 	break;
	// case OpDiv:
	// 	obj = context->get(ident->getValue());
	// 	ret = obj->div(ret);
	// 	break;
	// default:
	// 	throw "not support operater";
	// }
	// context->set(ident->getValue(), ret);
	// ASTExit ast_exit(ret, NomalExit);
	// return ast_exit;
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
			return ASTExit(LuryNil::getInstance(), NomalExit);
		}
		else {
			return else_stmt->eval(context);
		}
	}
}

ASTExit CompoundAST::eval(LuryContext *context) {
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
	return ASTExit(obj, NomalExit);
}

ASTExit FunctionStatementAST::eval(LuryContext *context) {
	context->setMethod(name, new LuryUserMethod(proc, params));
	return ASTExit(LuryBoolean::getInstance(true), NomalExit);
}

ASTExit ClassStatementAST::eval(LuryContext *) {
	LuryClass *klass = LuryClass::createClass(name);
	LuryContext context(klass);

	suit->eval(&context);
	return ASTExit(LuryNil::getInstance(), NomalExit);
}

ASTExit CreateInstanceAST::eval(LuryContext *context) {
	LuryClass *klass = LuryClass::getClass(name);
	LuryObject *obj = new LuryObject(klass);
	return ASTExit(obj, NomalExit);
}

ASTExit CallAST::eval(LuryContext *context) {
	string method_name = ((IdentifierAST *)callee)->getValue();
	LuryMethod *method = context->getMethod(method_name);
	vector<LuryObject *> fargs;

	for (auto itr : args) {
		ASTExit e = itr->eval(context);
		fargs.push_back(e.getReturnValue());
	}

	return method->call(context->getObject(), fargs);
}

ASTExit ReturnStatementAST::eval(LuryContext *context) {
	ASTExit expr_exit = expr->eval(context);
	ASTExit ast_exit(expr_exit.getReturnValue(), Return);
	return ast_exit;
}

ASTExit ContinueStatementAST::eval(LuryContext *context) {
	return ASTExit(LuryNil::getInstance(), Continue);
}

ASTExit BreakStatementAST::eval(LuryContext *context) {
	return ASTExit(LuryNil::getInstance(), Break);
}

ASTExit WhileStatementAST::eval(LuryContext *context) {
	ASTExit ast_exit(LuryNil::getInstance(), NomalExit);
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
			ast_exit = ASTExit(LuryNil::getInstance(), NomalExit);
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
	return ASTExit(LuryBoolean::getInstance(!boolean), NomalExit);
}
