#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * AVL树（平衡二叉搜索树）
 * 特性：任何节点的两个子树的高度差不超过1
 * 时间复杂度：O(log n) 查找、插入、删除
 * 通过旋转操作维持平衡
 */

struct AVLNode {
    int val;
    int height;      // 节点高度
    AVLNode* left;
    AVLNode* right;

    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    // 获取节点高度
    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    // 计算平衡因子
    int getBalance(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // 更新节点高度
    void updateHeight(AVLNode* node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    // 右旋转（LL情况）
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // 执行旋转
        x->right = y;
        y->left = T2;

        // 更新高度
        updateHeight(y);
        updateHeight(x);

        cout << "执行右旋转，新根节点: " << x->val << endl;
        return x;
    }

    // 左旋转（RR情况）
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // 执行旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        updateHeight(x);
        updateHeight(y);

        cout << "执行左旋转，新根节点: " << y->val << endl;
        return y;
    }

    // 插入节点
    AVLNode* insertHelper(AVLNode* node, int val) {
        // 1. 执行标准BST插入
        if (node == nullptr) {
            return new AVLNode(val);
        }

        if (val < node->val) {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->val) {
            node->right = insertHelper(node->right, val);
        }
        else {
            // 相等值不插入
            return node;
        }

        // 2. 更新当前节点的高度
        updateHeight(node);

        // 3. 获取平衡因子
        int balance = getBalance(node);

        // 4. 如果不平衡，有四种情况需要处理

        // Left Left情况
        if (balance > 1 && val < node->left->val) {
            cout << "检测到LL不平衡，节点: " << node->val << endl;
            return rotateRight(node);
        }

        // Right Right情况
        if (balance < -1 && val > node->right->val) {
            cout << "检测到RR不平衡，节点: " << node->val << endl;
            return rotateLeft(node);
        }

        // Left Right情况
        if (balance > 1 && val > node->left->val) {
            cout << "检测到LR不平衡，节点: " << node->val << endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left情况
        if (balance < -1 && val < node->right->val) {
            cout << "检测到RL不平衡，节点: " << node->val << endl;
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        // 返回未改变的节点指针
        return node;
    }

    // 找到最小值节点
    AVLNode* findMin(AVLNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    // 删除节点
    AVLNode* deleteHelper(AVLNode* node, int val) {
        // 1. 执行标准BST删除
        if (node == nullptr) {
            return node;
        }

        if (val < node->val) {
            node->left = deleteHelper(node->left, val);
        }
        else if (val > node->val) {
            node->right = deleteHelper(node->right, val);
        }
        else {
            // 要删除的节点
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    // 无子节点情况
                    temp = node;
                    node = nullptr;
                }
                else {
                    // 一个子节点情况
                    *node = *temp;
                }
                delete temp;
            }
            else {
                // 两个子节点情况
                AVLNode* temp = findMin(node->right);
                node->val = temp->val;
                node->right = deleteHelper(node->right, temp->val);
            }
        }

        if (node == nullptr) {
            return node;
        }

        // 2. 更新高度
        updateHeight(node);

        // 3. 获取平衡因子
        int balance = getBalance(node);

        // 4. 如果不平衡，处理四种情况

        // Left Left情况
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }

        // Left Right情况
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right情况
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Right Left情况
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // 查找节点
    AVLNode* searchHelper(AVLNode* node, int val) {
        if (node == nullptr || node->val == val) {
            return node;
        }

        if (val < node->val) {
            return searchHelper(node->left, val);
        }
        else {
            return searchHelper(node->right, val);
        }
    }

    // 中序遍历
    void inorderHelper(AVLNode* node) {
        if (node) {
            inorderHelper(node->left);
            cout << node->val << "(h:" << node->height << ",b:" << getBalance(node) << ") ";
            inorderHelper(node->right);
        }
    }

    // 前序遍历
    void preorderHelper(AVLNode* node) {
        if (node) {
            cout << node->val << "(h:" << node->height << ",b:" << getBalance(node) << ") ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // 检查是否为AVL树
    bool isAVLHelper(AVLNode* node) {
        if (node == nullptr) {
            return true;
        }

        int balance = getBalance(node);
        if (abs(balance) > 1) {
            return false;
        }

        return isAVLHelper(node->left) && isAVLHelper(node->right);
    }

    // 释放内存
    void destroyTree(AVLNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // 构造函数
    AVLTree() : root(nullptr) {}

    // 析构函数
    ~AVLTree() {
        destroyTree(root);
    }

    // 插入
    void insert(int val) {
        cout << "\n插入 " << val << ":" << endl;
        root = insertHelper(root, val);
    }

    // 删除
    void remove(int val) {
        cout << "\n删除 " << val << ":" << endl;
        root = deleteHelper(root, val);
    }

    // 查找
    bool search(int val) {
        return searchHelper(root, val) != nullptr;
    }

    // 中序遍历
    void inorderTraversal() {
        cout << "中序遍历: ";
        inorderHelper(root);
        cout << endl;
    }

    // 前序遍历
    void preorderTraversal() {
        cout << "前序遍历: ";
        preorderHelper(root);
        cout << endl;
    }

    // 层序遍历
    void levelOrderTraversal() {
        if (root == nullptr) {
            cout << "层序遍历: 空树" << endl;
            return;
        }

        cout << "层序遍历: ";
        queue<AVLNode*> q;
        q.push(root);

        while (!q.empty()) {
            AVLNode* current = q.front();
            q.pop();

            cout << current->val << "(h:" << current->height << ") ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }

    // 获取树的高度
    int getTreeHeight() {
        return getHeight(root);
    }

    // 检查是否为有效的AVL树
    bool isValidAVL() {
        return isAVLHelper(root);
    }

    // 打印树的结构（简单版本）
    void printTree() {
        cout << "\n=== AVL树结构 ===" << endl;
        if (root == nullptr) {
            cout << "空树" << endl;
            return;
        }

        queue<pair<AVLNode*, int>> q;
        q.push({ root, 0 });
        int currentLevel = 0;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (level > currentLevel) {
                cout << endl;
                currentLevel = level;
            }

            cout << node->val << "(h:" << node->height << ",b:" << getBalance(node) << ") ";

            if (node->left) {
                q.push({ node->left, level + 1 });
            }
            if (node->right) {
                q.push({ node->right, level + 1 });
            }
        }
        cout << "\n=================" << endl;
    }
};

// 测试函数
void testAVLTree() {
    AVLTree avl;

    cout << "=== AVL树测试 ===" << endl;

    // 测试插入（会触发各种旋转）
    cout << "\n--- 插入测试 ---" << endl;
    vector<int> values = { 10, 20, 30, 40, 50, 25 };

    for (int val : values) {
        avl.insert(val);
        avl.printTree();
        cout << "是否为有效AVL树: " << (avl.isValidAVL() ? "是" : "否") << endl;
    }

    // 遍历测试
    cout << "\n--- 遍历测试 ---" << endl;
    avl.inorderTraversal();
    avl.preorderTraversal();
    avl.levelOrderTraversal();

    // 查找测试
    cout << "\n--- 查找测试 ---" << endl;
    cout << "查找 25: " << (avl.search(25) ? "找到" : "未找到") << endl;
    cout << "查找 35: " << (avl.search(35) ? "找到" : "未找到") << endl;

    // 删除测试
    cout << "\n--- 删除测试 ---" << endl;
    avl.remove(10);
    avl.printTree();
    cout << "是否为有效AVL树: " << (avl.isValidAVL() ? "是" : "否") << endl;

    avl.remove(25);
    avl.printTree();
    cout << "是否为有效AVL树: " << (avl.isValidAVL() ? "是" : "否") << endl;

    cout << "\n最终中序遍历: ";
    avl.inorderTraversal();
    cout << "树的高度: " << avl.getTreeHeight() << endl;
}

int main() {
    testAVLTree();
    return 0;
}