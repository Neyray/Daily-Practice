// 二叉树的层次遍历
#include <iostream>
#include <vector>
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

// 层次遍历（进阶版：按层分组返回结果）
// 这在LeetCode（如题102）中非常常见，常用于需要知道“当前处于哪一层”的场景
vector<vector<int>> LevelOrderGrouped(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // 当前队列的长度，就是这一层的节点数
        vector<int> currentLevel;

        // 专门用一个 for 循环把当前层的所有节点一次性处理完
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();
            currentLevel.push_back(curr->val);

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        res.push_back(currentLevel); // 将当前层的结果加入总结果
    }
    return res;
}