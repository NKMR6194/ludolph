#pragma once

#include <map>
#include <vector>
#include <string>

using namespace std;

class ASTExit;
class LuryClass;
class LuryMethod;

class LuryObject {
private:
	map<string, LuryObject *> fields;
	map<string, LuryMethod *> methods;
	LuryClass *klass;

public:
	LuryObject(LuryClass *klass);
	~LuryObject();

	LuryObject *getField(string name);
	void setField(string name, LuryObject *field);
	LuryMethod *getMethod(string name);
	void setMethod(string name, LuryMethod *method);
	LuryClass *getClass();
	void setClass(LuryClass* k);

	ASTExit send(string name, vector<LuryObject *> args);

	bool isTrue();
	string toString();
};
