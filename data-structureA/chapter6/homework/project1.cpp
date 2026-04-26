//不同顺序输出树的叶子结点问题
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

// 二叉树节点结构
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 解析括号表示法构建二叉树
Node* buildTree(const string& s) {
    stack<Node*> st;
    Node* root = nullptr;
    Node* p = nullptr;
    int k = 0; // 1表示左子树，2表示右子树
    int i = 0, n = s.length();
    
    while (i < n) {
        if (s[i] == ' ') { 
            i++; 
            continue; 
        }
        if (s[i] == '(') {
            st.push(p); // 将刚创建的节点压栈，作为后续子节点的父节点
            k = 1;      // 接下来是左子节点
            i++;
        } else if (s[i] == ',') {
            k = 2;      // 接下来是右子节点
            i++;
        } else if (s[i] == ')') {
            st.pop();   // 当前子树处理完毕，父节点出栈
            i++;
        } else {
            // 解析可能的负号和多位整数
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            int val = 0;
            while (i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            val *= sign;
            
            p = new Node(val);
            if (root == nullptr) {
                root = p;
            } else {
                if (k == 1) st.top()->left = p;
                else if (k == 2) st.top()->right = p;
            }
        }
    }
    return root;
}

// (1) 从左到右获取叶子结点
void getLeavesLR(Node* root, vector<int>& res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->val);
        return;
    }
    getLeavesLR(root->left, res);
    getLeavesLR(root->right, res);
}

// (2) 从右到左获取叶子结点
void getLeavesRL(Node* root, vector<int>& res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->val);
        return;
    }
    getLeavesRL(root->right, res);
    getLeavesRL(root->left, res);
}

// (3) 层序遍历，每层从右向左
void getLevelOrderRL(Node* root, vector<int>& res) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        res.push_back(curr->val);
        // 注意顺序：先将右子节点入队，再将左子节点入队
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }
}

// 辅助函数：按格式输出数组
void printVec(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ifstream inFile("in.txt");
    
    string s;
    if (inFile >> s) {
        Node* root = buildTree(s);
        
        vector<int> leavesLR, leavesRL, levelRL;
        getLeavesLR(root, leavesLR);
        getLeavesRL(root, leavesRL);
        getLevelOrderRL(root, levelRL);
        
        printVec(leavesLR);
        printVec(leavesRL);
        printVec(levelRL);
    }
    return 0;
}