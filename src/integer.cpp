#include <cmath>

#include "include/integer.hpp"
#include "include/function.hpp"
#include "include/string.hpp"
#include "include/boolean.hpp"

LuryClass *CLASS_OBJ_INT;

LuryInteger::LuryInteger(int value) : LuryObject(CLASS_OBJ_INT), value(value) {}

void LuryInteger::init() {
	CLASS_OBJ_INT = LuryClass::createClass("Integer");

	CLASS_OBJ_INT->setClassMethod("this", new LuryObjMethod<LuryInteger>(&LuryInteger::constructor));
	CLASS_OBJ_INT->setMethod("to_s", new LuryObjMethod<LuryInteger>(&LuryInteger::to_s));
	CLASS_OBJ_INT->setMethod("+", new LuryObjMethod<LuryInteger>(&LuryInteger::add));
	CLASS_OBJ_INT->setMethod("-", new LuryObjMethod<LuryInteger>(&LuryInteger::sub));
	CLASS_OBJ_INT->setMethod("==", new LuryObjMethod<LuryInteger>(&LuryInteger::equal));
	CLASS_OBJ_INT->setMethod(">=", new LuryObjMethod<LuryInteger>(&LuryInteger::greaterOrEqual));
}

LuryObject* LuryInteger::constructor(vector<LuryObject *> args) {
	return new LuryInteger(0);
}

LuryObject* LuryInteger::add(vector<LuryObject *> args) {
	LuryObject *obj = args[0];

	if (obj->getClass() == CLASS_OBJ_INT) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value + i->value);
	}

	throw "Type error in Integer#+";
}

LuryObject* LuryInteger::sub(vector<LuryObject *> args) {
	LuryObject *obj = args[0];

	if (obj->getClass() == CLASS_OBJ_INT) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value - i->value);
	}

	throw "Type error in Integer#-";
}

LuryObject* LuryInteger::equal(vector<LuryObject *> args) {
	LuryObject *obj = args[0];

	if (obj->getClass() == CLASS_OBJ_INT) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value == i->value);
	}

	throw "Type error in Integer#==";
}

LuryObject* LuryInteger::greaterOrEqual(vector<LuryObject *> args) {
	LuryObject *obj = args[0];

	if (obj->getClass() == CLASS_OBJ_INT) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value >= i->value);
	}

	throw "Type error in Integer#>=";
}

LuryObject *LuryInteger::to_s(vector<LuryObject *> args) {
	return new LuryString(to_string(value));
}

/*
LuryObject* LuryInteger::sub(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value - i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value - i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex((double)value - i->getReal(), i->getImaginary());
	}
	throw "sub not impliment other object";
}

LuryObject* LuryInteger::mul(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value * i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value * i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex((double)value * i->getReal(), (double)value * i->getImaginary());
	}
	throw "mul not impliment other object";
}

LuryObject* LuryInteger::div(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value / i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value / i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		double denominator = i->getReal() * i->getReal() + i->getImaginary() * i->getImaginary();
		LuryComplex *numerator = (LuryComplex *)mul(i->conjugate());
		return new LuryComplex(numerator->getReal() / denominator, numerator->getImaginary() / denominator);
	}
	throw "div not impliment other object";
}

LuryObject* LuryInteger::mod(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value % i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(fmod(value, i->getValue()));
	}
	throw "mod not implement other object";
}

LuryObject* LuryInteger::equal(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value == i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return LuryBoolean::getInstance((double)value == i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return LuryBoolean::getInstance(false);
	}
	throw "equal not impliment other object";
}

LuryObject* LuryInteger::notEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value != i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value != i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return LuryBoolean::getInstance(true);
	}
	throw "notEqual not impliment other object";
}

LuryObject* LuryInteger::less(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value < i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return LuryBoolean::getInstance((double)value < i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "less not impliment other object";
}

LuryObject* LuryInteger::lessOrEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value <= i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return LuryBoolean::getInstance((double)value <= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "lessOrEqual not impliment other object";
}

LuryObject* LuryInteger::greater(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value > i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return LuryBoolean::getInstance((double)value > i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "greater not impliment other object";
}

LuryObject* LuryInteger::greaterOrEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return LuryBoolean::getInstance(value >= i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return LuryBoolean::getInstance((double)value >= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "greaterOrEqual not impliment other object";
}
*/
