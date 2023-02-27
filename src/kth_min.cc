#include "src/code.h"
#include "src/code_factory.h"

// 寻找第k小的元素，中序遍历
class KthMin : public Code {
public:
    static constexpr int kClassType = kKthMin;

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
    void display(TreeNode *head);
    int kthSmalltest(TreeNode *root, int k);

private:
    TreeNode *head;
    int res; // 返回值
    int rank; // 当前遍历位置，从1开始
};

void KthMin::Init() {
    std::vector<int> input{5,3,6,2,4,-1,-1,1};
    buildTree(input, head);
    res = 0;
    rank = 0;
}

// 层序遍历构建二叉树
void KthMin::buildTree(const std::vector<int>& input, TreeNode* &h) {
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

void KthMin::Print() {
    display(head);
}

void KthMin::display(TreeNode *head) {
    if (head == nullptr) {
        return;
    }
    display(head->left);
    std::cout << head->val << std::endl;
    display(head->right);
}

int KthMin::kthSmalltest(TreeNode *root, int k) {
    if (root == nullptr) {
        return 0;
    }
    kthSmalltest(root->left, k);
    rank++;
    if (rank == k) {
        res = root->val;
    }

    kthSmalltest(root->right, k);
    return 0;
}

void KthMin::Run() {
   std::cout << "KthMin run" << std::endl;
   kthSmalltest(head, 3);
   std::cout << "res: " << res << std::endl;
}

CODE_FACTORY_REGISTER(Code, KthMin)

