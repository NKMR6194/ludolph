#include

class FloatNumberLitAST : public AST {
	double value;
public:
	FloatNumberLitAST(double value) : AST(FloatNumberLitID), value(value){}
	~FloatNumberLitAST() {}
	int getFloatNumberValue() {return value;}
	void print() { cout << "(FloatNumberLitAST " << value << ")"; }
	ASTExit eval(LuryContext *context) {
		return ASTExit(new LuryFloating(value), NomalExit);
	}
};
