/*
输入方式：完全二叉树的存储方式，如ABC#D##；
现要求构造二叉链，判断是否是对称二叉树；
输出方式：如果是，输出"Yes"；如果不是，输出"No"。
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& s) {
    if (s.empty() || s[0] == '#') return nullptr;
    TreeNode* root = new TreeNode(s[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < s.size()) {
        TreeNode* current = q.front();
        q.pop();
        // 处理左子节点
        if (i < s.size()) {
            if (s[i] != '#') {
                current->left = new TreeNode(s[i]);
                q.push(current->left);
            }
            i++;
        }
        // 处理右子节点
        if (i < s.size()) {
            if (s[i] != '#') {
                current->right = new TreeNode(s[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

bool isMirror(TreeNode* t1, TreeNode* t2) {
    // 如果两棵树都为空，互为镜像
    if (!t1 && !t2) return true;
    // 如果其中一棵为空另一棵非空，不是镜像
    if (!t1 || !t2) return false;
    // 当前节点值相等，且t1左子树与t2右子树对称，且t1右子树与t2左子树对称
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    // 空树视为对称
    if (!root) return true;
    // 检查左右子树是否互为镜像
    return isMirror(root->left, root->right);
}

int main() {
    string s;
    cin >> s;
    TreeNode* root = buildTree(s);
    if (isSymmetric(root)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}