#include "../include/class.hpp"

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

void Init_test() {
	LuryClass::createClass("Test");
	LuryClass *klass = LuryClass::getClass("Test");
	klass->create_instance = create;
}

//g++ -shared -std=c++11 test.cpp -o test.so
