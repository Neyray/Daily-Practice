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
    int ans = 0;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
        if (node == nullptr) return;

        ans = max(ans, depth);

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    };

    dfs(root, 1);
    return ans;
}