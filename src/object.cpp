#include "../include/object.hpp"
#include <cmath>

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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
}

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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
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
	throw "add not impliment other object";
}

LuryObject* LuryComplex::add(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(real + i->real, imaginary + i->imaginary);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryComplex(real + i->getValue(), imaginary);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryComplex(real + i->getValue(), imaginary);
	}
	throw "not impliment add operation Complex and Object";
}

LuryObject* LuryComplex::sub(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(real + i->real, imaginary - i->imaginary);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryComplex(real - i->getValue(), imaginary);
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryComplex(real - i->getValue(), imaginary);
	}
	throw "not impliment sub operation Complex and Object";
}

LuryObject* LuryComplex::mul(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryComplex(real * i->real - imaginary * i->imaginary, real * i->imaginary + imaginary * i->real);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryComplex(real * i->getValue(), imaginary * i->getValue());
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryComplex(real * i->getValue(), imaginary * i->getValue());
	}
	throw "not impliment mul operation Complex and Object";
}

LuryObject* LuryComplex::div(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		double denominator = i->real * i->real + i->imaginary * i->imaginary;
		LuryComplex *numerator = (LuryComplex *)mul(i->conjugate());
		return new LuryComplex(numerator->real / denominator, numerator->imaginary / denominator);
	}
	else if (LuryInteger::classof(obj)) {
		LuryInteger *i = (LuryInteger *)obj;
		return new LuryComplex(real / i->getValue(), imaginary / i->getValue());
	}
	else if (LuryFloating::classof(obj)) {
		LuryFloating *i = (LuryFloating *)obj;
		return new LuryComplex(real / i->getValue(), imaginary / i->getValue());
	}
	throw "not impliment mul operation Complex and Object";
}

LuryObject* LuryComplex::equal(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryBoolean(real == i->real && imaginary == i->imaginary);
	}
	else if (LuryInteger::classof(obj)) {
		return new LuryBoolean(false);
	}
	else if (LuryFloating::classof(obj)) {
		return new LuryBoolean(false);
	}
	throw "not impliment equal operation Complex and Object";
}

LuryObject* LuryComplex::notEqual(LuryObject *obj) {
	if (LuryComplex::classof(obj)) {
		LuryComplex *i = (LuryComplex *)obj;
		return new LuryBoolean(real != i->real || imaginary != i->imaginary);
	}
	else if (LuryInteger::classof(obj)) {
		return new LuryBoolean(true);
	}
	else if (LuryFloating::classof(obj)) {
		return new LuryBoolean(true);
	}
	throw "not impliment not equal operation Complex and Object";
}

LuryObject* LuryBoolean::equal(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return new LuryBoolean(value == i->value);
	}
	throw "add not impliment other object";
}

LuryObject* LuryBoolean::notEqual(LuryObject *obj) {
	if (LuryBoolean::classof(obj)) {
		LuryBoolean *i = (LuryBoolean *)obj;
		return new LuryBoolean(value != i->value);
	}
	throw "add not impliment other object";
}
