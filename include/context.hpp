#ifndef LUDOLPH_CONTEXT_HPP
#define LUDOLPH_CONTEXT_HPP

#include <unordered_map>

using namespace std;

class LuryContext {
	unordered_map<string, LuryObject *>  env;
public:
	LuryContext() {}
	LuryContext(unordered_map<string, LuryObject *> env) : env(env) {}
	LuryObject* get(string key) { return env[key]; }
	LuryContext* copy() { return new LuryContext(env); }
	void set(string key, LuryObject *value) { env[key] = value; }
};

#endif
