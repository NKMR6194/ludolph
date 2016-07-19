#include <iostream>
#include "../include/lury.hpp"

using namespace std;

int main (int argc, char* argv[]) {
	lury::Driver drive;
	string file_path;

	if (argc < 2) {
		cout << "need file path" << endl;
		return 0;
	}

	luryInit();

	file_path = string(argv[1]);
	if (drive.parse_file(file_path)) {
		LuryClass mother("main");
		LuryContext *context = new LuryContext(&mother);
		context->setMethod("puts", new LuryFunction([](LuryObject *obj){ cout << obj->to_s() << endl; }));
		drive.ast->eval(context);
	}

	return 0;
}
