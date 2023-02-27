#include "src/code.h"
#include "src/code_factory.h"

// bfs求二叉树的最小高度，注意到叶子节点
class MinDepth : public Code {
public:
    static constexpr int kClassType = kMinDepth;

    struct TreeNode {
        int val{0};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
        TreeNode(int value) : val(value) {}
    };

    void Init();
    void Run();
    void Print();
    void buildTree(const std::vector<int>& input, TreeNode* &h);
    int bfs(TreeNode *root);

private:
    TreeNode *head;
};

// 层序遍历构建二叉树
void MinDepth::buildTree(const std::vector<int>& input, TreeNode* &h) {
    int n = input.size();
    if (n == 0 || input[0] < 0) {
        return;
    }
    std::vector<TreeNode*> nodes(n, nullptr);
    h = new TreeNode(input[0]);
    nodes[0] = h;
    for (int i = 1; i < n; i++) {
        if (input[i] == -1) {
            continue;
        }
        TreeNode *cur = new TreeNode(input[i]);
        int pIndex = (i-1)/2;
        bool isRight = (i % 2 == 0); // 偶数为右节点
        TreeNode *p = nodes[pIndex];
        if (p == nullptr) { // 父节点为空
            continue;
        }
        if (isRight) {
            p->right = cur;
        } else {
            p->left = cur;
        }
        nodes[i] = cur;
    }
}

void MinDepth::Init() {
    std::vector<int> input{3,9,20,-1,-1,15,7};
    buildTree(input, head);
}

void MinDepth::Print() {
}

int MinDepth::bfs(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int res = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    res++;
    while(!q.empty()) {
        int n = q.size();
        for (int i =0; i<n; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left == nullptr && cur->right == nullptr) { // 叶子节点
                return res;
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        res++;
    }
    return res;
}

void MinDepth::Run() {
   std::cout << "MinDepth run" << std::endl;
   int res = bfs(head);
   std::cout << res << std::endl;
}

CODE_FACTORY_REGISTER(Code, MinDepth)

