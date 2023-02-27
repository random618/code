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
    kMaxDepth = 2,
    kKthMin = 3,
    kAllPaths = 4,
    kPermute = 5,
    kMinDepth = 6,
    kFib = 7,
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
