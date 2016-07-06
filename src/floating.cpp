#include <cmath>

#include "../include/floating.hpp"
#include "../include/integer.hpp"
#include "../include/complex.hpp"
#include "../include/boolean.hpp"

LuryObject* LuryFloating::add(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(value + i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryFloating(value + i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(value + i->getReal(), i->getImaginary());
	}
	throw "add not impliment other object";
}

LuryObject* LuryFloating::sub(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(value - i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryFloating(value - i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(value - i->getReal(), i->getImaginary());
	}
	throw "sub not impliment other object";
}

LuryObject* LuryFloating::mul(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(value * i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryFloating(value * i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(value * i->getReal(), value * i->getImaginary());
	}
	throw "mul not impliment other object";
}

LuryObject* LuryFloating::div(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(value / i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryFloating(value / i->getValue());
	}
	throw "div not impliment other object";
}

LuryObject* LuryFloating::mod(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating(fmod(value, i->value));
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryFloating(fmod(value, i->getValue()));
	}
	throw "mod not implement other object";
}

LuryObject* LuryFloating::equal(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value == i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value == i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return new LuryBoolean(false);
	}
	throw "equal not impliment other object";
}

LuryObject* LuryFloating::notEqual(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value != i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value != i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return new LuryBoolean(true);
	}
	throw "notEqual not impliment other object";
}

LuryObject* LuryFloating::less(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value < i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value < i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Floating and Comprex";
	}
	throw "less not impliment other object";
}

LuryObject* LuryFloating::lessOrEqual(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value <= i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value <= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Floating and Comprex";
	}
	throw "lessOrEqual not impliment other object";
}

LuryObject* LuryFloating::greater(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value > i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value > i-> getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Floating and Comprex";
	}
	throw "greater not impliment other object";
}

LuryObject* LuryFloating::greaterOrEqual(LuryObject *obj) {
	if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean(value >= i->value);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value >= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Floating and Comprex";
	}
	throw "greaterOrEqual not impliment other object";
}
