#pragma once

#include "base.hpp"

class IntegerLitAST : public AST {
private:
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
