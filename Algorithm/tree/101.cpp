// 对称二叉树
#include <iostream>
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

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;

    function<bool(TreeNode*, TreeNode*)> isSame =
        [&](TreeNode* node1, TreeNode* node2) {
            if (node1 == nullptr || node2 == nullptr)
                return node1 == node2;

            if (node1->val != node2->val) return false;

            return isSame(node1->left, node2->right) &&
                   isSame(node1->right, node2->left);
        };

    return isSame(root->left, root->right);
}