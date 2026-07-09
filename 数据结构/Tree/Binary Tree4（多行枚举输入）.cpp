#include <iostream>
#include <unordered_map>  // 用于快速查找节点的哈希表
#include <vector>        // 存储节点值的动态数组
#include <set>           // 用于记录子节点集合
#include <stack>         // 实现非递归遍历的栈
using namespace std;

// 二叉树节点结构定义
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    int n;
    cin >> n;  // 读取节点数量

    // 创建节点映射表（字符 -> 节点指针）
    unordered_map<char, TreeNode*> nodes;
    set<char> children;      // 记录所有作为子节点出现的字符
    vector<char> nodeVals;   // 保存所有节点值（用于后续找根节点）

    // 构建二叉树
    for (int i = 0; i < n; ++i) {
        char val, left, right;
        cin >> val >> left >> right;
        nodeVals.push_back(val);   //确保每个字符只出现一次

        // 创建当前节点（如果不存在）
        if (!nodes[val]) nodes[val] = new TreeNode(val);

        // 处理左子树
        if (left != '#') {
            if (!nodes[left]) nodes[left] = new TreeNode(left);
            nodes[val]->left = nodes[left];
            children.insert(left);  // 记录为子节点
        }

        // 处理右子树
        if (right != '#') {
            if (!nodes[right]) nodes[right] = new TreeNode(right);
            nodes[val]->right = nodes[right];
            children.insert(right); // 记录为子节点
        }
    }

    // 寻找根节点（没有在children集合中出现的节点）
    char rootVal;
    for (char c : nodeVals) {
        if (children.find(c) == children.end()) {
            rootVal = c;
            break;
        }
    }

    TreeNode* root = nodes[rootVal];  // 获取根节点指针



    // 使用栈实现非递归前序遍历（节点指针 + 当前层级），实际上是DFS
    stack<pair<TreeNode*, int>> stk;
    stk.push({ root, 1 });  // 根节点层级为1

    while (!stk.empty()) {
        auto current = stk.top();
        stk.pop();
        TreeNode* node = current.first;
        int level = current.second;

        if (!node) continue;  // 跳过空节点

        // 输出格式：节点值 + 空格 + 层级
        cout << node->val << " " << level << endl;

        // 栈的特性：先压右节点，再压左节点（出栈顺序即为先左后右）
        stk.push({ node->right, level + 1 });  // 子节点层级+1
        stk.push({ node->left, level + 1 });
    }

    return 0;
}