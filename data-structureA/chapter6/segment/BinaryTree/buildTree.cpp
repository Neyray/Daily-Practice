#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

//1.给定先序和中序构造二叉树
// 辅助函数，携带数组边界索引
Node* helper1(const vector<int>& preorder, int preStart, int preEnd, 
              const vector<int>& inorder, int inStart, int inEnd) {
    // 递归终止条件：区间无效
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }
    
    // 先序的第一个元素就是根节点
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);
    
    // 在中序序列中找到根节点的位置
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != rootVal) {
        rootIndex++;
    }
    
    // 计算左子树的节点数量
    int leftSize = rootIndex - inStart;
    
    // 递归构造左右子树
    root->left = helper1(preorder, preStart + 1, preStart + leftSize, 
                         inorder, inStart, rootIndex - 1);
    root->right = helper1(preorder, preStart + leftSize + 1, preEnd, 
                          inorder, rootIndex + 1, inEnd);
                          
    return root;
}

Node* buildTree1(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;
    return helper1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}



//2.给定包含空节点（-1）的先序序列构造二叉树
// 辅助函数，使用引用类型传递索引，保证全局向前推进
Node* helper2(const vector<int>& preorder, int& idx) {
    // 数组越界保护
    if (idx >= preorder.size()) {
        return nullptr;
    }
    
    // 如果遇到 -1，说明是空节点，索引前移并返回空
    if (preorder[idx] == -1) {
        idx++;
        return nullptr;
    }
    
    // 创建当前根节点
    Node* root = new Node(preorder[idx]);
    idx++; // 消费掉当前值
    
    // 严格按照先序的“根-左-右”顺序递归
    root->left = helper2(preorder, idx);
    root->right = helper2(preorder, idx);
    
    return root;
}

Node* buildTree2(vector<int>& preorder) {
    int idx = 0; // 从第 0 个元素开始扫描
    return helper2(preorder, idx);
}


//3.给定后序和中序构造二叉树
// 辅助函数，携带数组边界索引
Node* helper3(const vector<int>& inorder, int inStart, int inEnd, 
              const vector<int>& postorder, int postStart, int postEnd) {
    // 递归终止条件
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }
    
    // 后序的最后一个元素是根节点
    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);
    
    // 在中序序列中找到根节点的位置
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != rootVal) {
        rootIndex++;
    }
    
    // 计算左子树的节点数量
    int leftSize = rootIndex - inStart;
    
    // 递归构造左右子树
    // 注意：后序数组的左子树区间是 [postStart, postStart + leftSize - 1]
    // 后序数组的右子树区间是 [postStart + leftSize, postEnd - 1]
    root->left = helper3(inorder, inStart, rootIndex - 1, 
                         postorder, postStart, postStart + leftSize - 1);
    root->right = helper3(inorder, rootIndex + 1, inEnd, 
                          postorder, postStart + leftSize, postEnd - 1);
                          
    return root;
}

Node* buildTree3(vector<int>& postorder, vector<int>& inorder) {
    if (postorder.empty() || inorder.empty()) return nullptr;
    return helper3(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}



//4.括号表示法
Node* buildTree4(const string& s) {
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