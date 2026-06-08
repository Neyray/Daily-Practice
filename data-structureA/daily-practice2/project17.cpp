#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

// 根据先序序列建树，-1 表示空节点
Node* buildTree() {
    int x;

    if (!(cin >> x)) {
        return NULL;
    }

    if (x == -1) {
        return NULL;
    }

    Node* root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// 中序遍历判断是否严格递增
bool isBST(Node* root, Node*& prev) {
    if (root == NULL) {
        return true;
    }

    // 1. 判断左子树
    if (!isBST(root->left, prev)) {
        return false;
    }

    // 2. 判断当前节点是否大于中序前驱
    if (prev != NULL && prev->val >= root->val) {
        return false;
    }

    // 3. 更新 prev
    prev = root;

    // 4. 判断右子树
    if (!isBST(root->right, prev)) {
        return false;
    }

    return true;
}

int main() {
    Node* root = buildTree();

    Node* prev = NULL;

    if (isBST(root, prev)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}