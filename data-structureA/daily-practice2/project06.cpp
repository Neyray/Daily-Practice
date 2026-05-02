//求二叉树叶子节点个数
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

//和project3---求二叉树的高度类似
int getCount(Node* root) {
    //如果root是空节点或者已经是叶子节点，那么就没有继续递归下去的必要了，需要返回
    if (root == NULL)return 0;
    if (root->left == NULL && root->right == NULL)return 1;

    //只有要么存在一个后继，要么存在两个后继的继续后面的递归代码
    //所以可能存在left存在，但是仍然访问right的情况，这个时候就需要加上判断条件root==NULL

    return getCount(root->left) + getCount(root->right);
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