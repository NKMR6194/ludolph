#include "include/object.hpp"
#include "include/class.hpp"
#include "include/function.hpp"
#include "include/boolean.hpp"
#include "include/string.hpp"
#include "include/ast_exit.hpp"

LuryObject::LuryObject(LuryClass *klass) : klass(klass) {}

LuryObject::~LuryObject() {}

LuryObject *LuryObject::getField(string name) {
	return fields[name];
}

void LuryObject::setField(string name, LuryObject *field) {
	fields[name] = field;
}

LuryMethod *LuryObject::getMethod(string name) {
	LuryMethod *method;

	method = methods[name];
	if (method == NULL) {
		method = klass->getMethod(name);
	}
	return method;
}

void LuryObject::setMethod(string name, LuryMethod *method) {
	methods[name] = method;
}

LuryClass *LuryObject::getClass() {
	return klass;
}

void LuryObject::setClass(LuryClass* k) {
	klass = k;
}

ASTExit LuryObject::send(string name, vector<LuryObject *> args) {
	LuryMethod *method = getMethod(name);

	return method->call(this, args);
}

bool LuryObject::isTrue() {
	ASTExit e = send("true?", {});
	LuryBoolean *obj = (LuryBoolean *)(e.getReturnValue());

	return obj->isTrue();
}

string LuryObject::toString() {
	ASTExit e = send("to_s", {});
	LuryString *obj = (LuryString *)(e.getReturnValue());

	return obj->getValue();
}
