#pragma once

#include "../ast_exit.hpp"

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
private:
	AstID ID;

public:
	AST(AstID id) : ID(id) {}
	virtual ~AST() {}
	AstID getValueID() const { return ID; }
	virtual void print() {}
	virtual ASTExit eval(LuryContext *context) { throw "not implement eval"; };
};
