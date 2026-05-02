//求二叉树的节点个数
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) :val(v), left(NULL), right(NULL) {}
};

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

//递归思想类似于project6
int getCount(Node* root){
    //如果是空节点就没有继续递归的必要了
    if(root==NULL){
        return 0;
    }

    return 1+getCount(root->left)+getCount(root->right);
}

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);

    string num;
    vector<int>node;
    while (getline(ss, num, ' ')) {
        if (!num.empty() && num.back() == '\r')num.pop_back();
        if (num.empty())continue;

        node.push_back(stoi(num));
    }

    int idx = 0;
    Node* root = buildTree(node, idx);

    cout << getCount(root);

    return 0;
}