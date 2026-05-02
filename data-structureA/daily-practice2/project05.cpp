//判断两个二叉树是否相同
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

//和project1---判断是否是对称二叉树类似
bool isSame(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)return true;
    if (root1 == NULL || root2 == NULL || root1->val != root2->val)return false;

    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

int main() {
    string str; vector<int>node;
    Node* root1 = NULL;
    Node* root2 = NULL;

    int i = 1;
    while (getline(cin, str) && i <= 2) {
        //必须声明在循环内部，不然会一直加
        vector<int>node;
        stringstream ss(str);
        string num;
        while (getline(ss, num, ' ')) {
            if (!num.empty() && num.back() == '\r')num.pop_back();
            if (num.empty())continue;

            node.push_back(stoi(num));
        }

        int idx = 0;
        if (i == 1) root1 = buildTree(node, idx);
        else root2 = buildTree(node, idx);

        i++;
    }

    if (isSame(root1, root2))cout << "YES";
    else cout << "NO";

    return 0;
}