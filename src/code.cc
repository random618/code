#include "src/code.h"

#include <iostream>
#include <string>

Code::Code() {}

Code::~Code() {}

void Code::Init() {
    std::cout << "code init" << std::endl;
}

void Code::Run() {
    std::cout << "code run" << std::endl;
}

void Code::Print() {
    std::cout << "code print" << std::endl;
}
