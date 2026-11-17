// 二叉树的前序遍历
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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*)> preorder = [&](TreeNode* node) {
        if (node == nullptr) return;

        ans.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    };

    preorder(root);

    return ans;
}