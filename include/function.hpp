#pragma once

#include <vector>
#include <string>
#include <functional>

#include "object.hpp"
#include "ast_exit.hpp"

using namespace std;

class AST;

extern LuryClass *CLASS_OBJ_FUNCTION;

class LuryMethod : public LuryObject {
public:
	LuryMethod() : LuryObject(CLASS_OBJ_FUNCTION) {}
	virtual ASTExit call(LuryObject *self, vector<LuryObject *> args) {
		throw "method error";
	}
	static void init();
};

template <typename T>
class LuryObjMethod : public LuryMethod {
private:
	function<LuryObject*(T*, vector<LuryObject *>)> method;

public:
	LuryObjMethod(function<LuryObject*(T*, vector<LuryObject *>)> method) :
		method(method)
	{}
	~LuryObjMethod() {}

	ASTExit call(LuryObject *self, vector<LuryObject *> args) {
		return ASTExit(method((T*)self, args), NomalExit);
	}
};

class LuryUserMethod : public LuryMethod {
private:
	AST *proc;
	vector<string> params;

public:
	LuryUserMethod(AST *proc, vector<string> params) : proc(proc), params(params) {}
	~LuryUserMethod() {}

	ASTExit call(LuryObject *self, vector<LuryObject *> args);
};


