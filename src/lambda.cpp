#include "../include/lambda.hpp"

LuryClass *CLASS_OBJ_LAMBDA;

LuryLambda::LuryLambda(list<string> params, AST *proc) :
	LuryObject(CLASS_OBJ_LAMBDA), params(params), proc(proc)
{}

void LuryLambda::init() {
	CLASS_OBJ_LAMBDA = LuryClass::createClass("Lambda");
}
