//使用输入构建一个二叉树，判断它是否是高度平衡的二叉树。本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 主函数：判断是否为平衡二叉树
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    // 递归检查高度，如果不平衡返回-1，否则返回实际高度
    int checkHeight(TreeNode* node) {
        if (!node) return 0;  // 空节点高度为0

        // 递归计算左子树高度
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // 左子树不平衡，直接返回

        // 递归计算右子树高度
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;  // 右子树不平衡，直接返回

        // 检查当前节点是否平衡（左右子树高度差不超过1）
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // 不平衡，返回-1
        }

        // 返回当前节点的高度
        return max(leftHeight, rightHeight) + 1;
    }
};

// 根据完全二叉树输入构建二叉树
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    // 创建根节点
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    vector<TreeNode*> queue;  // 用于层序遍历构建树
    queue.push_back(root);

    int i = 1;  // 从第二个元素开始处理
    while (i < nodes.size() && !queue.empty()) {
        TreeNode* current = queue.front();
        queue.erase(queue.begin());

        // 处理左子节点
        if (i < nodes.size()) {
            if (nodes[i] != "null") {
                current->left = new TreeNode(stoi(nodes[i]));
                queue.push_back(current->left);
            }
            i++;
        }

        // 处理右子节点
        if (i < nodes.size()) {
            if (nodes[i] != "null") {
                current->right = new TreeNode(stoi(nodes[i]));
                queue.push_back(current->right);
            }
            i++;
        }
    }

    return root;
}

// 解析输入字符串为节点数组
vector<string> parseInput(const string& input) {
    vector<string> nodes;
    stringstream ss(input);
    string node;

    // 按空格分割字符串
    while (ss >> node) {
        nodes.push_back(node);
    }

    return nodes;
}

// 释放二叉树内存，防止内存泄漏
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // 尝试从文件读取输入
    ifstream inFile("in.txt");
    ofstream outFile("out.txt");

    string line;

    // 如果文件存在，从文件读取；否则从控制台读取
    if (inFile.is_open()) {
        getline(inFile, line);
        inFile.close();
    }
    else {
        // 文件不存在时，从控制台输入
        cout << "请输入二叉树（格式：3 9 20 null null 15 7）：";
        getline(cin, line);
    }

    // 解析输入字符串并构建二叉树
    vector<string> nodes = parseInput(line);
    TreeNode* root = buildTree(nodes);

    // 创建解题对象并判断是否为平衡二叉树
    Solution solution;
    bool result = solution.isBalanced(root);

    // 根据结果输出True或False
    string output = result ? "True" : "False";

    // 输出到文件和控制台
    if (outFile.is_open()) {
        outFile << output << endl;
        outFile.close();
    }
    cout << output << endl;

    // 释放内存
    deleteTree(root);

    return 0;
}