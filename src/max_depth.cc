#include "src/code.h"
#include "src/code_factory.h"

// 根节点到最远叶子节点的路径节点数
class MaxDepth : public Code {
public:
    static constexpr int kClassType = kMaxDepth;

    struct TreeNode {
        int val{0};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
        TreeNode(int value) : val(value) {}
    };

    void Init();
    void Run();
    void Print();
    void display(TreeNode *head);
    int maxDep(TreeNode *head);

private:
    TreeNode *head;
};

void MaxDepth::Init() {
    TreeNode *T1 = new TreeNode(3);
    TreeNode *T2 = new TreeNode(9);
    TreeNode *T3 = new TreeNode(20);
    TreeNode *T4 = new TreeNode(15);
    TreeNode *T5 = new TreeNode(7);
    head = T1;
    T1->left = T2;
    T1->right = T3;
    T3->left = T4;
    T3->right = T5;
}

void MaxDepth::display(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    std::cout << head->val << std::endl;
    display(head->left);
    display(head->right);
}

void MaxDepth::Print() {
    display(head);
}

int MaxDepth::maxDep(TreeNode *head) {
    if (head == nullptr) {
        return 0;
    }
    int l = maxDep(head->left);
    int r = maxDep(head->right);
    return std::max(l, r) + 1;
}

void MaxDepth::Run() {
   std::cout << "MaxDepth run" << std::endl;
   int ret = maxDep(head);
   std::cout << "max depth: " << ret << std::endl;
}

CODE_FACTORY_REGISTER(Code, MaxDepth)
