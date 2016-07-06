#pragma once

#include "object.hpp"
#include "class.hpp"

class LuryComplex : public LuryObject {
	double real, imaginary;
public:
	LuryComplex(double real, double imaginary) : real(real), imaginary(imaginary){
		setClass(LuryClass::getClass("Complex"));
	}
	static void init() { LuryClass::createClass("Complex"); }
	static inline bool classof(LuryComplex const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Complex";
	}

	double getReal() { return real; }
	double getImaginary() { return imaginary; }
	LuryObject* conjugate() { return new LuryComplex(real, -imaginary); }
	string to_s() { return "(" + to_string(real) + "+" + to_string(imaginary) + "i)"; }
	LuryObject *add(LuryObject *obj);
	LuryObject *sub(LuryObject *obj);
	LuryObject *mul(LuryObject *obj);
	LuryObject *div(LuryObject *obj);
	LuryObject *equal(LuryObject *obj);
	LuryObject *notEqual(LuryObject *obj);
};
