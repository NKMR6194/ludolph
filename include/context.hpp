#pragma once

#include <unordered_map>

using namespace std;

class LuryContext {
	unordered_map<string, LuryObject *> env;
	LuryClass *klass;

public:
	LuryContext() {}
	LuryContext(unordered_map<string, LuryObject *> env) : env(env) {}
	LuryContext(LuryClass *klass) : klass(klass) {}
	LuryContext(unordered_map<string, LuryObject *> env, LuryClass *klass)
		: env(env), klass(klass) {}
	LuryObject* get(string key) { return env[key]; }
	LuryContext* copy() { return new LuryContext(env, klass); }
	LuryContext* copy(LuryClass *klass) { return new LuryContext(env, klass); }
	void set(string key, LuryObject *value) { env[key] = value; }
	void setMethod(string name, LuryFunction *func) { klass->setMethod(name, func); }
	LuryFunction *getMethod(string name) { return klass->getMethod(name); }
};
