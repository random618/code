#include "src/code.h"
#include "src/code_factory.h"

class Example : public Code {
public:
    static constexpr int kClassType = kExample;

    void Init();
    void Run();
    void Print();

private:
};

void Example::Init() {
}

void Example::Print() {
}

void Example::Run() {
   std::cout << "Example run" << std::endl;
}

CODE_FACTORY_REGISTER(Code, Example)

