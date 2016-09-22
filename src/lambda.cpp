#include "../include/lambda.hpp"

LuryClass *CLASS_OBJ_LAMBDA;

LuryLambda::LuryLambda(vector<string> params, AST *proc) :
	LuryObject(CLASS_OBJ_LAMBDA), params(params), proc(proc)
{}

void LuryLambda::init() {
	CLASS_OBJ_LAMBDA = LuryClass::createClass("Lambda");
}
