#include "../include/object.hpp"
#include "../include/class.hpp"
#include "../include/boolean.hpp"

string LuryObject::getClassName() const {
	return ((LuryClass *)klass)->getName();
}

LuryObject* LuryObject::luryOr(LuryObject *obj) {
	return new LuryBoolean(this->isTrue() || obj->isTrue());
}
