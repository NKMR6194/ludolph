#include "../include/object.hpp"
#include "../include/class.hpp"
#include "../include/boolean.hpp"
#include "../include/context.hpp"
#include "../include/ast_exit.hpp"

LuryObject::LuryObject(LuryObject *klass) : klass(klass) {}

LuryObject::~LuryObject() {}

LuryObject *LuryObject::getField(string name) {
	return fields[name];
}

void LuryObject::setField(string name, LuryObject *field) {
	fields[name] = field;
}

LuryObject *LuryObject::getMethod(string name) {
	LuryObject *method;

	method = methods[name];
	if (method == NULL) {
		method = ((LuryClass *) klass)->getMethod(name);
	}
	return method;
}

void LuryObject::setMethod(string name, LuryObject *method) {
	methods[name] = method;
}

LuryObject *LuryObject::getClass() {
	return klass;
}

void LuryObject::setClass(LuryObject* k) {
	klass = k;
}

ASTExit LuryObject::call(string name, list<LuryObject *> args) {
	LuryFunction *func = (LuryFunction *)getMethod(name);

	return func->eval(LuryContext((LuryClass *)this), args);
}

string LuryObject::to_s() {
	return "<" + ((LuryClass *)klass)->getName() + ">";
}

LuryObject* LuryObject::luryOr(LuryObject *obj) {
	return LuryBoolean::getInstance(this->isTrue() || obj->isTrue());
}
