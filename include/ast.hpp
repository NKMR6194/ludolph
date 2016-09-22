#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "object.hpp"
#include "function.hpp"
#include "nil.hpp"
#include "integer.hpp"
#include "string.hpp"
#include "boolean.hpp"
#include "lambda.hpp"
#include "context.hpp"
#include "ast_exit.hpp"

using namespace std;

enum AstID {
	EmptyID,
	BinaryOpID,
	BinaryAssignID,
	StringLitID,
	IntegerLitID,
	FloatNumberLitID,
	ImaginaryNumberLitID,
	NilLitID,
	BooleanLitID,
	LambdaLitID,
	IfStatementID,
	CompoundID,
	IdentifierID,
	FunctionID,
	ClassID,
	CreateInstanceID,
	CallID,
	ReturnStatementID,
	ContinueStatementID,
	BreakStatementID,
	WhileStatementID,
	NotID
};

enum OpID {
	OpAdd,
	OpSub,
	OpMul,
	OpDiv,
	OpMod,
	OpEqual,
	OpNotEqual,
	OpLess,
	OpLessOrEqual,
	OpGreater,
	OpGreaterOrEqual,
	OpOr
};

class AST {
	AstID ID;
public:
	AST(AstID id) : ID(id) {}
	virtual ~AST() {}
	AstID getValueID() const { return ID; }
	virtual void print() {}
	virtual ASTExit eval(LuryContext *context) { throw "not implement eval"; };
};

class EmptyAST : public AST {
public:
	EmptyAST() : AST(EmptyID) {}
	~EmptyAST() {}
};

class BinaryOpAST : public AST {
	OpID op;
	AST *lhs, *rhs;
public:
	BinaryOpAST(AST *lhs, AST *rhs, OpID op) : AST(BinaryOpID), lhs(lhs), rhs(rhs), op(op) {}
	~BinaryOpAST() {
		delete lhs;
		delete rhs;
	}
	OpID getOpId() { return op; }
	AST *getLhs() { return lhs; }
	AST *getRhs() { return rhs; }
	void print() {
		cout << "(BinaryOpAST ";
		lhs->print();
		rhs->print();
		cout << " )";
	}
	ASTExit eval(LuryContext *context);
};

class BinaryAssignAST : public AST {
	OpID op;
	AST *lhs, *rhs;
public:
	BinaryAssignAST(AST *lhs, AST *rhs, OpID op) : AST(BinaryAssignID), lhs(lhs), rhs(rhs), op(op) {}
	~BinaryAssignAST() {
		delete lhs;
		delete rhs;
	}
	OpID getOpId() { return op; }
	AST *getLhs() { return lhs; }
	AST *getRhs() { return rhs; }
	ASTExit eval(LuryContext *context);
};

class StringLitAST : public AST {
	string value;
public:
	StringLitAST(string value) : AST(StringLitID), value(value) {}
	~StringLitAST() {}
	ASTExit eval(LuryContext *context) {
		return ASTExit(new LuryString(value), NomalExit);
	}
};

class IntegerLitAST : public AST {
	int value;
public:
	IntegerLitAST(int value) : AST(IntegerLitID), value(value) {}
	~IntegerLitAST() {}
	int getIntegerValue() { return value; }
	void print() { cout << "(IntegerLitAST " << value << ")"; }
	ASTExit eval(LuryContext *context) {
		ASTExit ast_exit(new LuryInteger(value), NomalExit);
		return ast_exit;
	}
};

class NilLitAST : public AST {
public:
	NilLitAST() : AST(NilLitID) {}
	~NilLitAST() {}
	ASTExit eval(LuryContext *context) { return ASTExit((LuryObject *)LuryNil::getInstance(), NomalExit); }
};

class BooleanLitAST : public AST {
	bool value;
public:
	BooleanLitAST(bool value) : AST (BooleanLitID), value(value) {}
	~BooleanLitAST() {}
	ASTExit eval(LuryContext *context) { return ASTExit((LuryObject *)LuryBoolean::getInstance(value), NomalExit); }
};

class LambdaLitAST : public AST {
	vector<string> params;
	AST *expr;
public:
	LambdaLitAST(vector<string> params, AST *expr) : AST (LambdaLitID), params(params), expr(expr) {}
	~LambdaLitAST() {}
	ASTExit eval(LuryContext *context) {
		return ASTExit((LuryObject *)new LuryLambda(params, expr), NomalExit);
	}
};

class IfStatementAST : public AST {
	AST *condition, *then_stmt, *else_stmt;
public:
	IfStatementAST(AST *condition, AST *then_stmt)
		: AST(IfStatementID)
		, condition(condition)
		, then_stmt(then_stmt)
		, else_stmt(NULL) {}
	IfStatementAST(AST *condition, AST *then_stmt, AST *else_stmt)
		: AST(IfStatementID)
		, condition(condition)
		, then_stmt(then_stmt)
		, else_stmt(else_stmt) {}
	~IfStatementAST() {
		if (condition != NULL) delete condition;
		if (then_stmt != NULL) delete then_stmt;
		if (else_stmt != NULL) delete else_stmt;
	}
	void print() {
		cout << "(IfStatementAST";
		if (condition == NULL) {
			cout << "NULL";
		}
		condition->print();
		cout << " ";
		this->then_stmt->print();
		cout << " ";
		if (else_stmt != NULL) {
			else_stmt->print();
		}
		cout << ")";
	}
	ASTExit eval(LuryContext *context);
};

class CompoundAST : public AST {
private:
	list<AST *> list;
	void mergeBackAST(CompoundAST *ast) {
		for (auto stmt : ast->list) {
			this->push_back(stmt);
		}
		ast->list.clear();
		delete ast;
	}
	void mergeFrontAST(CompoundAST *ast) {
		auto itr = ast->list.rbegin();
		while (itr != ast->list.rend()) {
			this->push_front(*itr);
			itr++;
		}
		ast->list.clear();
		delete ast;
	}
public:
	CompoundAST() : AST(CompoundID) {}
	CompoundAST(AST *ast) : AST(CompoundID) {
		this->push_back(ast);
	}
	CompoundAST(AST *ast1, AST *ast2) : AST(CompoundID) {
		this->push_back(ast1);
		this->push_back(ast2);
	}
	~CompoundAST() {
		for (auto elem : list) {
			delete elem;
		}
	}
	void push_back(AST *ast) {
		switch (ast->getValueID()) {
		case CompoundID:
			mergeBackAST((CompoundAST *) ast);
			break;
		case EmptyID:
			break;
		default:
			list.push_back(ast);
		}
	}
	void push_front(AST *ast) {
		switch (ast->getValueID()) {
		case CompoundID:
			mergeFrontAST((CompoundAST *) ast);
			break;
		case EmptyID:
			break;
		default:
			list.push_front(ast);
		}
	}
	void print() { cout << "(CompoundAST)"; }
	ASTExit eval(LuryContext *context);
};

class IdentifierAST : public AST {
	string value;
public:
	IdentifierAST(string value) : AST(IdentifierID), value(value) {}
	ASTExit eval(LuryContext *context);
	string getValue() { return value; }
};

class FunctionStatementAST : public AST {
	string name;
	vector<string> params;
	AST *proc;
public:
	FunctionStatementAST(string name, AST *proc) : AST(FunctionID), name(name), proc(proc) {}
	FunctionStatementAST(string name, vector<string> params, AST *proc) : AST(FunctionID), name(name), params(params), proc(proc) {}
	ASTExit eval(LuryContext *context);
};

class ClassStatementAST : public AST {
	string name;
	AST *suit;
public:
	ClassStatementAST(string name, AST *suit) : AST(ClassID), name(name), suit(suit) {};
	ASTExit eval(LuryContext *context);
};

class CreateInstanceAST : public AST {
	string name;
public:
	CreateInstanceAST(string name) : AST(CreateInstanceID), name(name) {};
	ASTExit eval(LuryContext *context);
};

class CallAST : public AST {
	AST *callee;
	vector<AST *>args;
public:
	CallAST(AST *callee, vector<AST *> args) : AST(CallID), callee(callee), args(args) {}
	ASTExit eval(LuryContext *context);
};

class ReturnStatementAST : public AST {
	AST *expr;
public:
	ReturnStatementAST(AST *expr) : AST(ReturnStatementID), expr(expr) {}
	ASTExit eval(LuryContext *context);
};

class ContinueStatementAST : public AST {
public:
	ContinueStatementAST() : AST(ContinueStatementID) {}
	~ContinueStatementAST() {}
	ASTExit eval(LuryContext *context);
};

class BreakStatementAST : public AST {
public:
	BreakStatementAST() : AST(BreakStatementID) {}
	~BreakStatementAST() {}
	ASTExit eval(LuryContext *context);
};

class WhileStatementAST : public AST {
	AST *condition;
	AST *stmt;
	AST *else_stmt;
public:
	WhileStatementAST(AST *condition, AST *stmt, AST *else_stmt) : AST(WhileStatementID), condition(condition), stmt(stmt), else_stmt(else_stmt) {}
	~WhileStatementAST() {}
	ASTExit eval(LuryContext *context);
};

class NotAST : public AST {
	AST *expr;
public:
	NotAST(AST *expr) : AST(NotID), expr(expr) {}
	~NotAST() {}
	ASTExit eval(LuryContext *context);
};
