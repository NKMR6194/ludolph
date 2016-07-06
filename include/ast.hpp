#pragma once

#include <iostream>
#include <list>
#include "object.hpp"
#include "nil.hpp"
#include "integer.hpp"
#include "string.hpp"
#include "floating.hpp"
#include "complex.hpp"
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

class FloatNumberLitAST : public AST {
	double value;
public:
	FloatNumberLitAST(double value) : AST(FloatNumberLitID), value(value){}
	~FloatNumberLitAST() {}
	int getFloatNumberValue() {return value;}
	void print() { cout << "(FloatNumberLitAST " << value << ")"; }
	ASTExit eval(LuryContext *context) {
		return ASTExit(new LuryFloating(value), NomalExit);
	}
};

class ImaginaryNumberLitAST : public AST {
	double imaginary;
public:
	ImaginaryNumberLitAST(double imaginary) : AST(ImaginaryNumberLitID), imaginary(imaginary) {}
	~ImaginaryNumberLitAST() {}
	ASTExit eval(LuryContext *context) {
		return ASTExit(new LuryComplex(0.0, imaginary), NomalExit);
	}
};

class NilLitAST : public AST {
public:
	NilLitAST() : AST(NilLitID) {}
	~NilLitAST() {}
	ASTExit eval(LuryContext *context) { return ASTExit((LuryObject *)new LuryNil(), NomalExit); }
};

class BooleanLitAST : public AST {
	bool value;
public:
	BooleanLitAST(bool value) : AST (BooleanLitID), value(value) {}
	~BooleanLitAST() {}
	ASTExit eval(LuryContext *context) { return ASTExit((LuryObject *)new LuryBoolean(value), NomalExit); }
};

class LambdaLitAST : public AST {
	list<string> params;
	AST *expr;
public:
	LambdaLitAST(list<string> params, AST *expr) : AST (LambdaLitID), params(params), expr(expr) {}
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
	list<AST *> list;
public:
	CompoundAST() : AST(CompoundID) {}
	CompoundAST(AST *ast) : AST(CompoundID) {
		this->push_back(ast);
	}
	~CompoundAST() {
		for (auto elem : list) {
			delete elem;
		}
	}
	void push_back(AST *ast) { list.push_back(ast); }
	void push_front(AST *ast) { list.push_front(ast); }
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
	list<string> params;
	AST *proc;
public:
	FunctionStatementAST(string name, list<string> params, AST *proc) : AST(FunctionID), name(name), params(params), proc(proc) {}
	FunctionStatementAST(string name, list<string> *params, AST *proc) : AST(FunctionID), name(name), params(*params), proc(proc) {}
	ASTExit eval(LuryContext *context);
};

class ClassStatementAST : public AST {
	string name;
public:
	ClassStatementAST(string name) : AST(ClassID), name(name) {};
	ASTExit eval(LuryContext *context);
};

class CallAST : public AST {
	AST *callee;
	list<AST *>args;
public:
	CallAST(AST *callee, list<AST *> args) : AST(CallID), callee(callee), args(args) {}
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
