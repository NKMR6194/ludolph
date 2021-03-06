#include "../include/complex.hpp"
#include "../include/integer.hpp"
#include "../include/floating.hpp"
#include "../include/boolean.hpp"

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
	throw "not impliment div operation Complex and Object";
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
