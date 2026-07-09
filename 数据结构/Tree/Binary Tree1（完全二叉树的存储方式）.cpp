/*
对于第i个数，其左节点为2i,右节点为21+1，父节点为i mod 2
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

    //队列是先进先出，即后进前出
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    int n = s.size();

    //注意！这里的队列不是循环队列！
    while (!q.empty() && i < n) {
        TreeNode* current = q.front();

        //实际上是双指针

        //通过删除操作来实现指针移动
        q.pop();

        //这两个是按顺序进行的，即每个循环中都会进入两个if之中
        
        // 左子节点
        if (i < n) {
            char c = s[i];
            if (c != '#') {
                current->left = new TreeNode(c);
                q.push(current->left);
            }
            i++;
        }
        // 右子节点
        if (i < n) {
            char c = s[i];
            if (c != '#') {
                current->right = new TreeNode(c);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    string s;
    cin >> s;
    TreeNode* root = buildTree(s);
    preorder(root);
    return 0;
}