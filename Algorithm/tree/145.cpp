// 二叉树的后序遍历
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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*)> postorder = [&](TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr) postorder(root->left);
        if (root->right != nullptr) postorder(root->right);
        ans.push_back(root->val);
    };

    postorder(root);
    return ans;
}