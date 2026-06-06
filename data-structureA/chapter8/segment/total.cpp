//重点！！！
//AVL<BST<普通二叉排序树
//插入/删除都是：普通二叉排序树操作→检查平衡→旋转(AVL树特有)
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

void updateHeight(Node* root) {
    if (root == NULL) {
        return;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

// 右旋
Node* rightRotate(Node* a) {
    Node* b = a->left;
    Node* temp = b->right;

    b->right = a;
    a->left = temp;

    updateHeight(a);
    updateHeight(b);

    return b;
}

// 左旋
Node* leftRotate(Node* a) {
    Node* b = a->right;
    Node* temp = b->left;

    b->left = a;
    a->right = temp;

    updateHeight(a);
    updateHeight(b);

    return b;
}

// 检查平衡并旋转
Node* balance(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    updateHeight(root);

    int bf = getBalance(root);

    // 左边高，可能是 LL 或 LR
    if (bf > 1) {
        // LL 型
        if (getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        // LR 型
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // 右边高，可能是 RR 或 RL
    if (bf < -1) {
        // RR 型
        if (getBalance(root->right) <= 0) {
            return leftRotate(root);
        }

        // RL 型
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// AVL 插入
Node* insertNode(Node* root, int x) {
    if (root == NULL) {
        return new Node(x);
    }

    if (x < root->data) {
        root->left = insertNode(root->left, x);
    } else if (x > root->data) {
        root->right = insertNode(root->right, x);
    } else {
        return root;
    }

    return balance(root);
}

// 找左子树最大结点
Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// AVL 删除
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

        // 叶子结点
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 只有右子树
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 只有左子树
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 左右子树都有
        else {
            Node* maxNode = findMax(root->left);
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
        }
    }

    return balance(root);
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

// 中序遍历：可以用来检查是否仍然满足 BST 性质
void inorder(Node* root, bool& first) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, first);

    if (!first) {
        cout << " ";
    }

    cout << root->data;
    first = false;

    inorder(root->right, first);
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