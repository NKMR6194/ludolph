#include <cmath>

#include "../include/integer.hpp"
#include "../include/floating.hpp"
#include "../include/complex.hpp"
#include "../include/boolean.hpp"

LuryObject* LuryInteger::add(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryInteger(value + i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value + i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex((double)value + i->getReal(), i->getImaginary());
	}
	throw "add not impliment other object";
}

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
		return new LuryBoolean(value == i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean((double)value == i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return new LuryBoolean(false);
	}
	throw "equal not impliment other object";
}

LuryObject* LuryInteger::notEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value != i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryFloating((double)value != i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		return new LuryBoolean(true);
	}
	throw "notEqual not impliment other object";
}

LuryObject* LuryInteger::less(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value < i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean((double)value < i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "less not impliment other object";
}

LuryObject* LuryInteger::lessOrEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value <= i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean((double)value <= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "lessOrEqual not impliment other object";
}

LuryObject* LuryInteger::greater(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value > i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean((double)value > i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "greater not impliment other object";
}

LuryObject* LuryInteger::greaterOrEqual(LuryObject *obj) {
	if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryBoolean(value >= i->value);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryBoolean((double)value >= i->getValue());
	}
	else if (LuryComplex::classof(obj)) {
		throw "can not compare Integer and Comprex";
	}
	throw "greaterOrEqual not impliment other object";
}
