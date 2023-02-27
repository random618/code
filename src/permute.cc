#include "src/code.h"
#include "src/code_factory.h"

// 全排列
class Permute : public Code {
public:
    static constexpr int kClassType = kPermute;

    void Init();
    void Run();
    void Print();
    void backtrack(std::vector<int> &cur, int idx);

private:
    std::vector<int> nums;
    std::vector<std::vector<int>> result;
};

void Permute::Init() {
    std::vector<int> input{3,4,6};
    nums = std::move(input);
}

void Permute::Print() {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// cur为当前已经遍历的节点，idx为即将遍历的索引
void Permute::backtrack(std::vector<int> &cur, int idx) {
    if (idx == nums.size()) { // 遍历完了
        result.push_back(cur);
    }
    for (int i = 0; i < nums.size(); i++) {
        if (std::find(cur.begin(), cur.end(), nums[i]) == cur.end()) { // nums[i]未遍历，加入路径
            cur.push_back(nums[i]);
            backtrack(cur, idx+1);
            cur.pop_back();
        } else {
            continue;
        }
    }
}

void Permute::Run() {
   std::cout << "Permute run" << std::endl;
   std::vector<int> cur;
   backtrack(cur, 0);
}

CODE_FACTORY_REGISTER(Code, Permute)

