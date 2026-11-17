// 二叉树的右视图
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

// 深度优先遍历
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
        if (node == nullptr) return;

        // 当前层第一次访问的节点，就是最右侧节点

        // 由于ans的大小在变，所以不用担心右&左节点重复加入ans
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }

        // 先右后左，保证每层优先访问右边节点
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    };

    dfs(root, 0);
    return ans;
}