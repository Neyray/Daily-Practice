#include <iostream>
#include <queue>
using namespace std;

/**
 * 红黑树（Red-Black Tree）
 * 一种自平衡的二叉搜索树
 *
 * 红黑树的性质：
 * 1. 每个节点要么是红色，要么是黑色
 * 2. 根节点是黑色
 * 3. 所有叶子节点（NIL节点）都是黑色
 * 4. 如果一个节点是红色，那么它的两个子节点都是黑色
 * 5. 从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点
 *
 * 时间复杂度：O(log n) 查找、插入、删除
 */

enum Color { RED, BLACK };

struct RBNode {
    int val;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int x) : val(x), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    RBNode* root;
    RBNode* NIL;  // 哨兵节点，表示所有叶子节点

    // 初始化NIL节点
    void initializeNIL() {
        NIL = new RBNode(0);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = nullptr;
    }

    // 左旋转
    void leftRotate(RBNode* x) {
        RBNode* y = x->right;
        x->right = y->left;

        if (y->left != NIL) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;

        cout << "左旋转节点 " << x->val << endl;
    }

    // 右旋转
    void rightRotate(RBNode* x) {
        RBNode* y = x->left;
        x->left = y->right;

        if (y->right != NIL) {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;

        cout << "右旋转节点 " << x->val << endl;
    }

    // 插入修复
    void insertFixup(RBNode* z) {
        while (z->parent && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                // 父节点是祖父节点的左子节点
                RBNode* y = z->parent->parent->right;  // 叔叔节点

                if (y->color == RED) {
                    // 情况1：叔叔节点是红色
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                    cout << "插入修复情况1：重新着色" << endl;
                }
                else {
                    if (z == z->parent->right) {
                        // 情况2：叔叔是黑色，且z是右子节点
                        z = z->parent;
                        leftRotate(z);
                        cout << "插入修复情况2：左旋转" << endl;
                    }
                    // 情况3：叔叔是黑色，且z是左子节点
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                    cout << "插入修复情况3：重新着色并右旋转" << endl;
                }
            }
            else {
                // 父节点是祖父节点的右子节点（对称情况）
                RBNode* y = z->parent->parent->left;

                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                    cout << "插入修复情况1（对称）：重新着色" << endl;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                        cout << "插入修复情况2（对称）：右旋转" << endl;
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                    cout << "插入修复情况3（对称）：重新着色并左旋转" << endl;
                }
            }
        }
        root->color = BLACK;  // 根节点始终为黑色
    }

    // 插入节点
    void insertHelper(RBNode* z) {
        RBNode* y = nullptr;
        RBNode* x = root;

        // 找到插入位置
        while (x != NIL) {
            y = x;
            if (z->val < x->val) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nullptr) {
            root = z;
        }
        else if (z->val < y->val) {
            y->left = z;
        }
        else {
            y->right = z;
        }

        // 新节点的左右子节点都是NIL
        z->left = NIL;
        z->right = NIL;
        z->color = RED;  // 新节点为红色

        // 修复红黑树性质
        insertFixup(z);
    }

    // 用v替换u
    void transplant(RBNode* u, RBNode* v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // 找到最小值节点
    RBNode* minimum(RBNode* x) {
        while (x->left != NIL) {
            x = x->left;
        }
        return x;
    }

    // 删除修复
    void deleteFixup(RBNode* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                RBNode* w = x->parent->right;  // 兄弟节点

                if (w->color == RED) {
                    // 情况1：兄弟节点是红色
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                    cout << "删除修复情况1：兄弟节点红色" << endl;
                }

                if (w->left->color == BLACK && w->right->color == BLACK) {
                    // 情况2：兄弟节点的两个子节点都是黑色
                    w->color = RED;
                    x = x->parent;
                    cout << "删除修复情况2：兄弟子节点都是黑色" << endl;
                }
                else {
                    if (w->right->color == BLACK) {
                        // 情况3：兄弟节点右子节点是黑色，左子节点是红色
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                        cout << "删除修复情况3：转换为情况4" << endl;
                    }
                    // 情况4：兄弟节点右子节点是红色
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                    cout << "删除修复情况4：兄弟右子节点红色" << endl;
                }
            }
            else {
                // 对称情况
                RBNode* w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                }
                else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // 删除节点
    void deleteHelper(RBNode* z) {
        RBNode* y = z;
        RBNode* x;
        Color yOriginalColor = y->color;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z) {
                x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if (yOriginalColor == BLACK) {
            deleteFixup(x);
        }

        delete z;
    }

    // 查找节点
    RBNode* searchHelper(RBNode* node, int val) {
        if (node == NIL || node->val == val) {
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
    void inorderHelper(RBNode* node) {
        if (node != NIL) {
            inorderHelper(node->left);
            cout << node->val << "(" << (node->color == RED ? "R" : "B") << ") ";
            inorderHelper(node->right);
        }
    }

    // 检查红黑树性质
    bool isValidRBHelper(RBNode* node, int& blackCount, int currentBlackCount) {
        if (node == NIL) {
            if (blackCount == -1) {
                blackCount = currentBlackCount;
            }
            return blackCount == currentBlackCount;
        }

        // 检查红色节点的子节点是否都是黑色
        if (node->color == RED) {
            if ((node->left != NIL && node->left->color == RED) ||
                (node->right != NIL && node->right->color == RED)) {
                return false;
            }
        }

        int newBlackCount = currentBlackCount + (node->color == BLACK ? 1 : 0);

        return isValidRBHelper(node->left, blackCount, newBlackCount) &&
            isValidRBHelper(node->right, blackCount, newBlackCount);
    }

    // 释放内存
    void destroyTree(RBNode* node) {
        if (node != NIL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    // 构造函数
    RedBlackTree() {
        initializeNIL();
        root = NIL;
    }

    // 析构函数
    ~RedBlackTree() {
        destroyTree(root);
        delete NIL;
    }

    // 插入
    void insert(int val) {
        cout << "\n插入 " << val << ":" << endl;
        RBNode* z = new RBNode(val);
        insertHelper(z);
    }

    // 删除
    void remove(int val) {
        cout << "\n删除 " << val << ":" << endl;
        RBNode* z = searchHelper(root, val);
        if (z != NIL) {
            deleteHelper(z);
        }
        else {
            cout << "未找到要删除的节点" << endl;
        }
    }

    // 查找
    bool search(int val) {
        return searchHelper(root, val) != NIL;
    }

    // 中序遍历
    void inorderTraversal() {
        cout << "中序遍历: ";
        inorderHelper(root);
        cout << endl;
    }

    // 层序遍历
    void levelOrderTraversal() {
        if (root == NIL) {
            cout << "层序遍历: 空树" << endl;
            return;
        }

        cout << "层序遍历: ";
        queue<RBNode*> q;
        q.push(root);

        while (!q.empty()) {
            RBNode* current = q.front();
            q.pop();

            if (current != NIL) {
                cout << current->val << "(" << (current->color == RED ? "R" : "B") << ") ";

                q.push(current->left);
                q.push(current->right);
            }
        }
        cout << endl;
    }

    // 检查是否为有效的红黑树
    bool isValidRBTree() {
        if (root == NIL) return true;

        // 检查根节点是否为黑色
        if (root->color != BLACK) {
            return false;
        }

        int blackCount = -1;
        return isValidRBHelper(root, blackCount, 0);
    }

    // 获取黑高度
    int getBlackHeight() {
        int height = 0;
        RBNode* current = root;

        while (current != NIL) {
            if (current->color == BLACK) {
                height++;
            }
            current = current->left;
        }

        return height;
    }

    // 打印树的结构
    void printTree() {
        cout << "\n=== 红黑树结构 ===" << endl;
        if (root == NIL) {
            cout << "空树" << endl;
            return;
        }

        queue<pair<RBNode*, int>> q;
        q.push({ root, 0 });
        int currentLevel = 0;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (level > currentLevel) {
                cout << endl;
                currentLevel = level;
            }

            if (node != NIL) {
                cout << node->val << "(" << (node->color == RED ? "R" : "B") << ") ";
                q.push({ node->left, level + 1 });
                q.push({ node->right, level + 1 });
            }
        }
        cout << "\n=================" << endl;
    }
};

// 测试函数
void testRedBlackTree() {
    RedBlackTree rbt;

    cout << "=== 红黑树测试 ===" << endl;

    // 插入测试
    cout << "\n--- 插入测试 ---" << endl;
    vector<int> values = { 10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8 };

    for (int val : values) {
        rbt.insert(val);
        rbt.printTree();
        cout << "是否为有效红黑树: " << (rbt.isValidRBTree() ? "是" : "否") << endl;
    }