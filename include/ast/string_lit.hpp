#pragma once

#include "base.hpp"

class StringLitAST : public AST {
	string value;
public:
	StringLitAST(string value) : AST(StringLitID), value(value) {}
	~StringLitAST() {}
	ASTExit eval(LuryContext *context) {
		return ASTExit(new LuryString(value), NomalExit);
	}
};
