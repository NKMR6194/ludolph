#ifndef LUDOLPH_OBJECT_HPP
#define LUDOLPH_OBJECT_HPP

#include <string>
#include <list>
#include <functional>

using namespace std;

enum ClassID {
	LuryObjectID,
	LuryNilID,
	LuryIntegerID,
	LuryFloatingID,
	LuryComplexID,
	LuryBooleanID,
	LuryStringID,
	LuryLambdaID,
	LuryFunctionID
};

class AST;
class LuryContext;

class LuryObject {
	ClassID cid;
public:
	LuryObject() : cid(LuryObjectID) {}
	LuryObject(ClassID cid) : cid(cid) {}
	virtual LuryObject* add(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* sub(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* mul(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* div(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* equal(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* notEqual(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* less(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* lessOrEqual(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* greater(LuryObject *obj) { throw "add not impliment in object"; }
	virtual LuryObject* greaterOrEqual(LuryObject *obj) { throw "add not impliment in object"; }
	virtual string to_s() {}
	virtual bool isTrue() { return true; }
	ClassID getClassID() const { return cid; }
};

class LuryNil : public LuryObject {
public:
	LuryNil() : LuryObject(LuryNilID) {}
	static inline bool classof(LuryNil const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryNilID;
	}

	bool isTrue() const { return false; }
	string to_s() const { return "nil"; }
};

class LuryInteger : public LuryObject {
	int value;
public:
	LuryInteger(int value) : LuryObject(LuryIntegerID), value(value) {}
	static inline bool classof(LuryInteger const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryIntegerID;
	}

	LuryObject* add(LuryObject *obj);
	LuryObject* sub(LuryObject *obj);
	LuryObject* mul(LuryObject *obj);
	LuryObject* div(LuryObject *obj);
	LuryObject* equal(LuryObject *obj);
	LuryObject* notEqual(LuryObject *obj);
	LuryObject* less(LuryObject *obj);
	LuryObject* lessOrEqual(LuryObject *obj);
	LuryObject* greater(LuryObject *obj);
	LuryObject* greaterOrEqual(LuryObject *obj);
	int getValue() { return value; }
	string to_s() { return to_string(value); }
};

class LuryFloating : public LuryObject {
	double value;
public:
	LuryFloating(double value) : LuryObject(LuryFloatingID), value(value) {}
	static inline bool classof(LuryFloating const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryFloatingID;
	}

	LuryObject* add(LuryObject *obj);
	LuryObject* sub(LuryObject *obj);
	LuryObject* mul(LuryObject *obj);
	LuryObject* div(LuryObject *obj);
	LuryObject* equal(LuryObject *obj);
	LuryObject* notEqual(LuryObject *obj);
	LuryObject* less(LuryObject *obj);
	LuryObject* lessOrEqual(LuryObject *obj);
	LuryObject* greater(LuryObject *obj);
	LuryObject* greaterOrEqual(LuryObject *obj);
	double getValue() { return value; }
	string to_s() { return to_string(value); }
};

class LuryComplex : public LuryObject {
	double real;
	double imaginary;
public:
	LuryComplex(double real, double imaginary) : LuryObject(LuryComplexID), real(real), imaginary(imaginary) {}
	static inline bool classof(LuryComplex const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryComplexID;
	}

	double getReal() { return real; }
	double getImaginary() { return imaginary; }

	LuryObject* add(LuryObject *obj);
	LuryObject* sub(LuryObject *obj);
	LuryObject* mul(LuryObject *obj);
	LuryObject* div(LuryObject *obj);
	LuryObject* equal(LuryObject *obj);
	LuryObject* notEqual(LuryObject *obj);

	LuryObject* conjugate() { return new LuryComplex(real, -imaginary); }
	string to_s() { return "(" + to_string(real) + "+" + to_string(imaginary) + "i)"; }
};

class LuryBoolean : public LuryObject {
	bool value;
public:
	LuryBoolean(bool value) : LuryObject(LuryBooleanID), value(value) {}
	static inline bool classof(LuryBoolean const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryBooleanID;
	}

	LuryObject* equal(LuryObject *obj);
	LuryObject* notEqual(LuryObject *obj);

	string to_s() { return value ? "true" : "false"; }
	bool isTrue() { return value; }
	bool isFalse() { return !value; }
};

class LuryString : public LuryObject {
	std::string value;
public:
	LuryString(string value) : LuryObject(LuryStringID), value(value) {}
	LuryString(int num) : LuryObject(LuryStringID), value(to_string(num)) {}
	static inline bool classof(LuryString const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryStringID;
	}

	LuryObject* add(LuryObject *obj) {
		return new LuryString(value + obj->to_s());
	}
	string to_s() { return value; }
};

enum FunctionType {
	Instruction,
	NativeFunc
};

class LuryFunction : public LuryObject {
	FunctionType func_type;
	list<string> params;
	AST *proc;
	function<void(LuryObject *)> nfunc;
public:
	LuryFunction(list<string> params, AST *proc) : LuryObject(LuryFunctionID), func_type(Instruction), params(params), proc(proc) {}
	LuryFunction(function<void(LuryObject *)> nfunc) : LuryObject(LuryFunctionID), func_type(NativeFunc), nfunc(nfunc) {}
	~LuryFunction() {}
	static inline bool classof(LuryFunction const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryFunctionID;
	}

	AST* getProc() { return proc; }
	list<string> getParams() { return params; }
	FunctionType getFunctionType() { return func_type; }
	void eval(LuryObject *obj) { return nfunc(obj); }
	string to_s() { return "<function>"; }
};

class LuryLambda : public LuryObject {
	list<string> params;
	AST *expr;
public:
	LuryLambda(list<string> params, AST *expr) : LuryObject(LuryLambdaID), params(params), expr(expr) {}
	~LuryLambda() {}
	static inline bool classof(LuryLambda const*) { return true; }
	static inline bool classof(LuryObject const *object) {
		return object->getClassID() == LuryLambdaID;
	}

	AST* getProc() { return expr; }
	list<string> getParams() { return params; }
	string to_s() { return "<lambda>"; }
};

#endif
