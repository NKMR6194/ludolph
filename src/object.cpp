#include "../include/object.hpp"
#include "../include/class.hpp"
#include "../include/boolean.hpp"
#include "../include/context.hpp"
#include "../include/ast_exit.hpp"

LuryObject::LuryObject(LuryObject *klass) : klass(klass) {}

LuryObject::~LuryObject() {}

ASTExit LuryObject::call(string name, list<LuryObject *> args) {
	LuryObject *obj = getField(name);
	LuryFunction *func;

	if (obj->klass == CLASS_OBJ_FUNCTION) {
		func = (LuryFunction *)obj;
	}
	else {
		func = ((LuryClass *)klass)->getMethod(name);
	}

	return func->eval(LuryContext((LuryClass *)this), args);
}

LuryObject* LuryObject::luryOr(LuryObject *obj) {
	return LuryBoolean::getInstance(this->isTrue() || obj->isTrue());
}
