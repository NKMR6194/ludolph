#pragma once

#include <unordered_map>

#include "object.hpp"
#include "function.hpp"

using namespace std;

class LuryContext {
private:
	unordered_map<string, LuryObject *> env;
	LuryObject *object;

public:
	LuryContext(LuryObject *object);

	inline LuryObject* get(string key) { return env[key]; }
	inline void set(string key, LuryObject *value) { env[key] = value; }

	inline void setMethod(string name, LuryFunction *func) { object->setMethod(name, func); }
	inline LuryFunction *getMethod(string name) { return (LuryFunction *)(object->getMethod(name)); }
	inline LuryObject *getObject() { return object; }
};
