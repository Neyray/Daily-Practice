// 二叉树的中序遍历
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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*)> inorder = [&](TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr) inorder(root->left);
        ans.push_back(root->val);
        if (root->right != nullptr) inorder(root->right);
    };

    inorder(root);

    return ans;
}