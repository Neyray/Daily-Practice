// 二叉树的边界
// 逆时针输出二叉树边界
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return {};

    vector<int> ans;
    ans.push_back(root->val);

    // 1. 左边界：优先向左，不包含叶子节点
    TreeNode* p = root->left;

    while (p != nullptr) {
        if (p->left != nullptr || p->right != nullptr) {
            ans.push_back(p->val);
        }

        if (p->left != nullptr) p = p->left;
        else p = p->right;
    }

    // 2. 所有叶子节点：DFS，先左后右
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            // 根节点已经添加过，避免重复
            if (node != root) ans.push_back(node->val);
            return;
        }

        dfs(node->left);
        dfs(node->right);
    };

    dfs(root);

    // 3. 右边界：优先向右，不包含叶子节点
    vector<int> temp;
    p = root->right;

    while (p != nullptr) {
        if (p->left != nullptr || p->right != nullptr) {
            temp.push_back(p->val);
        }

        if (p->right != nullptr) p = p->right;
        else p = p->left;
    }

    // 右边界需要从下往上输出
    for (int i = (int)temp.size() - 1; i >= 0; --i) {
        ans.push_back(temp[i]);
    }

    return ans;
}