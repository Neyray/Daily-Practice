/*
输入方式：完全二叉树的存储方式，如ABC#D##；
现要求构造二叉链，数出二叉树中单节点的个数；
输出方式：直接输出数字
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;


struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

int countSingle(TreeNode* root) {
    /*
    你使用条件判断if (root->left != NULL)和if (root->right != NULL)，这会跳过对空子树的处理。然而，正确的做法是
    无论子节点是否存在都应调用递归函数，因为函数开头有if (!root) return;的判空机制。
    */
    if (!root) return 0;

    // 初始化计数器
    int cnt = 0;

    // 检查当前节点是否为单子节点
    // (root->left == nullptr) != (root->right == nullptr) 表示一个子节点为空，另一个子节点不为空
    if ((root->left == nullptr) != (root->right == nullptr)) {
        cnt = 1; // 是单子节点，cnt设置为1
    }

    // 递归计算左子树和右子树中的单子节点数量，并加上当前节点的计数
    return cnt + countSingle(root->left) + countSingle(root->right);
}


TreeNode* buildTree(const string& s) {
    int n = s.size();
    if (n == 0 || s[0] == '#') {
        return NULL;
    }

    TreeNode* root = new TreeNode(s[0]);
    queue<TreeNode*>q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (i < n) {
            char c = s[i];
            if (c != '#') {
                TreeNode* node = new TreeNode(c);
                current->left = node;
                q.push(node);
            }
        }
        i++;

        if (i < n) {
            char c = s[i];
            if (c != '#') {
                TreeNode* node = new TreeNode(c);
                current->right = node;
                q.push(node);
            }
        }
        i++;
    }
    return root;
}

int main() {
    string s;
    cin >> s;
    TreeNode* root = buildTree(s);
    cout << countSingle(root) << endl;
    return 0;
}