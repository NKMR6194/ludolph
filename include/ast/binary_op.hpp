#pragma once

#include "base.hpp"

class BinaryOpAST : public AST {
private:
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
