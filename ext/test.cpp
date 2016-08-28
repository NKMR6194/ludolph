#include "../include/class.hpp"
#include "../include/context.hpp"

#include <iostream>

class ExtTest : public LuryObject {
public:
	string to_s() { return "Beyond the layer!!"; }
	static inline bool classof(ExtTest const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassName() == "Test";
	}
};

LuryObject *create() {
	return new ExtTest();
}

extern "C" void Init_test(LuryContext *context) {
	LuryClass::createClass("Test");
	LuryClass *klass = LuryClass::getClass("Test");
	klass->create_instance = create;
	context->set("Test", klass);
}

//g++ -shared -std=c++11 test.cpp ../src/context.cpp ../src/class.cpp ../src/boolean.cpp -o test.so
