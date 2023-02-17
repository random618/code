#include "src/code.h"
#include "src/code_factory.h"

// 核心思想，从后往前遍历，保持栈里元素从小到大排列
class NextGreater : public Code {
public:
    static constexpr int kClassType = kNextGreater;
    void Init();
    void Run();
    void Print();

private:
    std::vector<int> nums;
    std::vector<int> res;
};

void NextGreater::Init() {
    std::vector<int> input{2,1,2,4,3};
    nums = std::move(input);

    std::vector<int> output(5, 0);
    res = std::move(output);
}

void NextGreater::Print() {
    for (auto e : res) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void NextGreater::Run() {
    int n = nums.size();
    std::stack<int> s; // 从后往前遍历，栈里的元素位置肯定在它后面
    for (int i = n-1; i >= 0; i--) {
        while(!s.empty() && nums[i] >= s.top()) { // 栈里放当前最大的元素
            s.pop();
        }
        if (s.empty()) { // 栈里没有比它更大的元素
            res[i] = -1;
        } else {
            res[i] = s.top();
        }
        s.push(nums[i]);
    }
}

/*
void NextGreater::Run() {
   std::cout << "NextGreater run" << std::endl;
   for (int i = 0; i < nums.size(); i++) {
       for (int j = i+1; j < nums.size(); j++) {
           if (nums[j] > nums[i]) {
               result[i] = nums[j];
               break;
           }
       }
   }
}
*/

CODE_FACTORY_REGISTER(Code, NextGreater)

