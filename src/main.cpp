#include <iostream>
#include "include/lury.hpp"

using namespace std;

LuryObject *lury_puts(LuryObject *obj, vector<LuryObject *> args) {
	cout << args.front()->toString() << endl;
	return LuryNil::getInstance();
}

int main (int argc, char* argv[]) {
	lury::Driver drive;
	string file_path;

	if (argc < 2) {
		cout << "need file path" << endl;
		return 0;
	}

	luryInit();

	file_path = argv[1];
	if (drive.parse_file(file_path)) {
		LuryObject mother(CLASS_OBJ_OBJECT);
		LuryContext *context = new LuryContext(&mother);
		context->setMethod("puts", new LuryObjMethod<LuryObject>(&lury_puts));
		drive.ast->eval(context);
	}

	return 0;
}
