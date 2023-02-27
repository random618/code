#include <iostream>
#include <memory>
#include "src/code_factory.h"
#include "src/code.h"

int main() {
	std::unique_ptr<Code> code = CodeFactory::GetCode(kFib);
	if (code == nullptr) {
		std::cout << "null code" << std::endl;
		return 0;
	}
	code->Init();
	code->Run();
	code->Print();
	return 0;
}
