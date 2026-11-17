// 二叉树的后序遍历
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    if (root == nullptr) return {};

    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* p = st.top();
        st.pop();

        ans.push_back(p->val);

        if (p->left != nullptr) st.push(p->left);
        if (p->right != nullptr) st.push(p->right);
    }

    for (int i = 0; i < ans.size() / 2; ++i) {
        swap(ans[i], ans[ans.size() - 1 - i]);
    }

    return ans;
}