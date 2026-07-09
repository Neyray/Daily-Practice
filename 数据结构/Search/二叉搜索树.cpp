#include <iostream>
#include <queue>
using namespace std;

/* BST
左子树节点值 小于 当前节点；

右子树节点值 大于 当前节点；

左右子树也都是二叉搜索树。

*/


struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

TreeNode* search(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

//AVL
struct AVLNode {
    int val, height;
    AVLNode* left, * right;
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode* insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // 4 种不平衡情况
    if (balance > 1 && key < node->left->val) return rotateRight(node);          // LL
    if (balance < -1 && key > node->right->val) return rotateLeft(node);         // RR
    if (balance > 1 && key > node->left->val) {                                   // LR
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->val) {                                 // RL
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}






//红黑树
enum Color { RED, BLACK };

struct RBNode {
    int val;
    Color color;
    RBNode* left, * right, * parent;
    RBNode(int x) : val(x), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
    RBNode* root;

    void rotateLeft(RBNode*& root, RBNode*& x) {
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(RBNode*& root, RBNode*& y) {
        RBNode* x = y->left;
        y->left = x->right;
        if (x->right) x->right->parent = y;
        x->parent = y->parent;
        if (!y->parent) root = x;
        else if (y == y->parent->left) y->parent->left = x;
        else y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(RBNode*& root, RBNode*& node) {
        RBNode* parent = nullptr, * grandparent = nullptr;
        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left) {
                RBNode* uncle = grandparent->right;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = uncle->color = BLACK;
                    node = grandparent;
                }
                else {
                    if (node == parent->right) {
                        node = parent;
                        rotateLeft(root, node);
                    }
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rotateRight(root, grandparent);
                }
            }
            else {
                RBNode* uncle = grandparent->left;
                if (uncle && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = uncle->color = BLACK;
                    node = grandparent;
                }
                else {
                    if (node == parent->left) {
                        node = parent;
                        rotateRight(root, node);
                    }
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rotateLeft(root, grandparent);
                }
            }
        }
        root->color = BLACK;
    }

public:
    RBTree() : root(nullptr) {}

    void insert(int val) {
        RBNode* node = new RBNode(val);
        RBNode* y = nullptr;
        RBNode* x = root;

        while (x) {
            y = x;
            if (val < x->val) x = x->left;
            else x = x->right;
        }

        node->parent = y;
        if (!y) root = node;
        else if (val < y->val) y->left = node;
        else y->right = node;

        fixInsert(root, node);
    }
};