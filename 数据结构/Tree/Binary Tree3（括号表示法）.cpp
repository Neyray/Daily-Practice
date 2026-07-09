#include <iostream>
#include <string>
using namespace std;

// 二叉树节点结构定义
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

/*
解析括号表示法的字符串为二叉树（类似LISP语法）
示例输入：A(B(D,E),C(,F)) 对应树结构：
    A
   / \
  B   C
 / \   \
D   E   F
*/

TreeNode* parse(string s) {
    if (s.empty()) return nullptr;  // 处理空字符串

    // 提取根节点（直到遇到第一个左括号）
    int rootEnd = 0;
    while (rootEnd < s.size() && s[rootEnd] != '(') {
        rootEnd++;  // 找到根节点结束位置
    }
    string rootStr = s.substr(0, rootEnd);  // 截取根节点字符串
    if (rootStr.empty()) return nullptr;    // 根节点不能为空
    TreeNode* root = new TreeNode(rootStr[0]);  // 创建根节点（取第一个字符）

    // 如果没有子树部分（如输入是单个字符"A"）
    if (rootEnd >= s.size()) return root;

    // 提取子树部分：去掉外层的括号
    // 假设输入格式正确，最后一个字符是')'，所以s.size()-rootEnd-2
    string childrenPart = s.substr(rootEnd + 1, s.size() - rootEnd - 2);

    // 分割左右子树（寻找最外层逗号）
    int split_idx = -1;
    int level = 0;  // 括号层级计数器
    for (int i = 0; i < childrenPart.size(); ++i) {
        if (childrenPart[i] == '(') level++;    // 进入嵌套括号
        else if (childrenPart[i] == ')') level--; // 退出嵌套括号
        else if (childrenPart[i] == ',' && level == 0) {  // 找到分割逗号
            split_idx = i;
            break;
        }
    }

    // 分割左右子树字符串
    string leftPart, rightPart;
    if (split_idx != -1) {  // 存在右子树
        leftPart = childrenPart.substr(0, split_idx);
        rightPart = childrenPart.substr(split_idx + 1);
    }
    else {  // 只有左子树（例如输入"A(B)"）
        leftPart = childrenPart;
        rightPart = "";
    }

    // 递归构建子树
    if (!leftPart.empty()) root->left = parse(leftPart);   // 处理左子树
    if (!rightPart.empty()) root->right = parse(rightPart); // 处理右子树

    return root;
}

// 前序遍历
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << endl;    // 先访问根节点
    preorder(root->left);         // 再遍历左子树
    preorder(root->right);        // 最后遍历右子树
}

int main() {
    string s;
    getline(cin, s);  // 读取整行输入（允许包含空格）
    TreeNode* root = parse(s);
    preorder(root);
    return 0;
}