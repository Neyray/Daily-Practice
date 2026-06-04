//二叉排序树---插入、删除
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// 插入结点
Node* insertNode(Node* root, int x) {
    if (root == NULL) {
        return new Node(x);
    }

    if (x < root->data) {
        root->left = insertNode(root->left, x);
    } else if (x > root->data) {
        root->right = insertNode(root->right, x);
    }

    return root;
}

// 找左子树中的最大结点
Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// 删除结点
Node* deleteNode(Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // 找到了要删除的结点

        // 情况1：叶子结点
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 情况2：只有右子树
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 情况3：只有左子树
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 情况4：左右子树都有
        // 用左子树中的最大值替代
        else {
            Node* maxNode = findMax(root->left);
            root->data = maxNode->data;

            // 删除左子树中原来的最大结点
            root->left = deleteNode(root->left, maxNode->data);
        }
    }

    return root;
}

// 先序遍历
void preorder(Node* root, bool& first) {
    if (root == NULL) {
        return;
    }

    if (!first) {
        cout << " ";
    }
    cout << root->data;
    first = false;

    preorder(root->left, first);
    preorder(root->right, first);
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        root = deleteNode(root, x);
    }

    bool first = true;
    preorder(root, first);

    return 0;
}