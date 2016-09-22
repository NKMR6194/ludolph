#include "../include/lury.hpp"

void luryInit() {
	LuryClass::init();
	LuryMethod::init();

	LuryBoolean::init();
	// LuryComplex::init();
	// LuryFloating::init();
	LuryInteger::init();
	// LuryLambda::init();
	LuryNil::init();
	LuryString::init();
}
