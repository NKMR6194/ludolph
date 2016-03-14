#include <iostream>
#include <string>
#include "../include/driver.hpp"
#include "../include/ast.hpp"
#include "../include/context.hpp"

using namespace std;

int main (int argc, char* argv[]) {
	lury::Driver drive;
	string file_path;

	if (argc < 2) {
		cout << "need file path" << endl;
		return 0;
	}

	file_path = string(argv[1]);
	if (drive.parse_file(file_path)) {
		LuryContext *context = new LuryContext();
		context->set("puts", new LuryFunction([](LuryObject *obj){ cout << obj->to_s() << endl; }));
		drive.ast->eval(context);
	}

	return 0;
}
