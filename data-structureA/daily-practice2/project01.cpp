//给定一棵二叉树，检查它是否是轴对称的（镜像对称）
//一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;

    Node(int v) :left(NULL), right(NULL), val(v) {}
};

//使用递归创建
Node* buildTree(vector<int>& preorder, int& idx) {
    if (idx >= preorder.size())return NULL;
    if (preorder[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;

    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

bool helper(Node* left, Node* right) {
    //！！！
    //这个写在前面，只要两个节点都为NULL的话就会在这里返回，之后的就是单个节点为NULL的情况
    if (left == NULL && right == NULL)return true;

    if (left == NULL || right == NULL || left->val != right->val)return false;

    return helper(left->left, right->right) && helper(left->right, right->left);
}

bool isMirror(Node* root) {
    if (root == NULL)return true;
    
    return helper(root->left, root->right);
}

int main() {
    string str;
    getline(cin,str);
    stringstream ss(str);

    vector<int>node;
    string num;
    while(getline(ss,num,' ')){
        if(!num.empty() && num.back()=='\r'){
            num.pop_back();
        }
        if(num.empty())continue;

        node.push_back(stoi(num));
    }

    int idx = 0;
    Node* root = buildTree(node, idx);

    if (isMirror(root))cout << "YES";
    else cout << "NO";

    return 0;
}