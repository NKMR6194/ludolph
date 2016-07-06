#pragma once

#include "base.hpp"

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
