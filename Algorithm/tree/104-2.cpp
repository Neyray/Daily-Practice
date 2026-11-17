// 二叉树的最大深度
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
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

int maxDepth(TreeNode* root) {
    function<int(TreeNode*)> getHeight = [&](TreeNode* node) {
        if (node == nullptr) return 0;

        return 1 + max(getHeight(node->left), getHeight(node->right));
    };

    int result = getHeight(root);

    return result;
}