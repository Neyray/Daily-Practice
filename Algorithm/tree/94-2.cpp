// 二叉树的中序遍历
#include <iostream>
#include <vector>
#include <stack>
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
    if (root == nullptr) return {};

    vector<int> ans;
    stack<TreeNode*> st;

    TreeNode* p = root;

    while (!st.empty() || p != nullptr) {
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }

        if (!st.empty()) {
            p = st.top();
            st.pop();

            ans.push_back(p->val);

            p = p->right;
        }
    }

    return ans;
}