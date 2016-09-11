#pragma once

#include "object.hpp"
#include "class.hpp"

extern LuryClass *CLASS_OBJ_COMPLEX;

class LuryComplex : public LuryObject {
private:
	const double real, imaginary;

public:
	LuryComplex(double real, double imaginary);

	static void init();
	static inline bool classof(LuryComplex const*) { return true; }
	static inline bool classof(LuryObject *object) {
		return object->getClass() == CLASS_OBJ_COMPLEX;
	}

	inline double getReal() { return real; }
	inline double getImaginary() { return imaginary; }
	inline LuryObject* conjugate() { return new LuryComplex(real, -imaginary); }
	inline string to_s() {
		return "(" + to_string(real) + "+" + to_string(imaginary) + "i)";
	}
	LuryObject *add(LuryObject *obj);
	LuryObject *sub(LuryObject *obj);
	LuryObject *mul(LuryObject *obj);
	LuryObject *div(LuryObject *obj);
	LuryObject *equal(LuryObject *obj);
	LuryObject *notEqual(LuryObject *obj);
};
