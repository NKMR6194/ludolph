#pragma once

#include "object.hpp"

enum ASTExitReason {
	NomalExit,
	Return,
	Break,
	Continue,
	Yield,
	ExceptionThrow
};

class ASTExit {
	LuryObject *return_value;
	ASTExitReason exit_reason;
public:
	ASTExit() : return_value(new LuryNil()), exit_reason(NomalExit) {}
	ASTExit(LuryObject *return_value, ASTExitReason exit_reason) : return_value(return_value), exit_reason(exit_reason) {}
	~ASTExit() {}
	ASTExitReason getExitReason() { return exit_reason; }
	LuryObject* getReturnValue() { return return_value; }
};
