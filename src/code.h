#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>

enum CodeType {
    kExample = 0,
    kNextGreater = 1,
};

class Code {
public:
    Code();
    ~Code();

    virtual void Init();
    virtual void Run();
    virtual void Print();
private:
};
