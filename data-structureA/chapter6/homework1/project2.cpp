//判断完全二叉树
#include <iostream>
#include <fstream>
#include <string>
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

// 解析括号表示法构建二叉树（与第一题完全相同）
Node* buildTree(const string& s) {
    stack<Node*> st;
    Node* root = nullptr;
    Node* p = nullptr;
    int k = 0; 
    int i = 0, n = s.length();
    
    while (i < n) {
        if (s[i] == ' ') { i++; continue; }
        if (s[i] == '(') {
            st.push(p);
            k = 1;
            i++;
        } else if (s[i] == ',') {
            k = 2;
            i++;
        } else if (s[i] == ')') {
            st.pop();
            i++;
        } else {
            int sign = 1;
            if (s[i] == '-') { sign = -1; i++; }
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

// 判断是否为完全二叉树
bool isCompleteBinaryTree(Node* root) {
    if (!root) return true;
    
    queue<Node*> q;
    q.push(root);
    bool encountered_null = false; // 是否遇到了空节点
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr == nullptr) {
            // 遇到了空节点，标记为 true
            encountered_null = true;
        } else {
            // 如果遇到过空节点，但当前节点又是非空的，说明不是完全二叉树
            if (encountered_null) return false;
            
            // 将左右子节点入队（即使子节点是 nullptr 也要入队占位）
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}

int main() {
    ifstream inFile("in.txt");
    
    string s;
    if (inFile >> s) {
        Node* root = buildTree(s);
        if (isCompleteBinaryTree(root)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}