/*【问题描述】

设计一个动态二叉排序树（BST），支持插入整数关键字，并实现以下功能：  

1. 中序遍历输出有序序列。  

2. 范围查询：输出所有介于 [a, b] 之间的关键字（按升序）。若区间内无关键字，输出 NULL。

【输入形式】

从文件输入（in.txt）：  

- 第一行为操作数 m。  

- 接下来 m 行，每行格式为：  

  - I key：插入关键字 key（若已存在则忽略）。  

  - T：输出当前树的中序遍历序列。  

  - Q a b：查询区间 [a, b] 内的所有关键字。

【输出形式】

输出到文件（out.txt）：  

- 对 T 操作，输出中序序列，以空格分隔。  

- 对 Q 操作，输出区间内关键字（按升序），若不存在则输出 NULL。

【样例输入】

9

I 5

I 3

I 7

T

Q 4 6

I 6

Q 4 7

Q 8 10

T

【样例输出】

3 5 7

5

5 6 7

NULL

3 5 6 7

【要求】

1. 必须手动实现BST的插入、中序遍历和范围查询。

2. 范围查询的时间复杂度为 O(h + n)（h为树高，n为结果数量），禁止全树遍历后筛选。

3. 中序遍历和范围查询结果必须严格按升序输出。*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 二叉排序树节点定义
struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// 二叉排序树类
class BST {
private:
    BSTNode* root;

    // 递归插入函数
    BSTNode* insertRec(BSTNode* node, int key) {
        if (!node) return new BSTNode(key);
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        }
        else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    // 递归中序遍历函数
    void inOrderRec(BSTNode* node, vector<int>& result) {
        if (!node) return;
        inOrderRec(node->left, result);
        result.push_back(node->key);
        inOrderRec(node->right, result);
    }

    // 递归范围查询函数
    void rangeQueryRec(BSTNode* node, int a, int b, vector<int>& result) {
        if (!node) return;

        // 当前节点值在区间左侧，只查右子树
        if (node->key < a) {
            rangeQueryRec(node->right, a, b, result);
        }
        // 当前节点值在区间右侧，只查左子树
        else if (node->key > b) {
            rangeQueryRec(node->left, a, b, result);
        }
        // 当前节点在区间内，先查左子树，添加当前节点，再查右子树
        else {
            rangeQueryRec(node->left, a, b, result);
            result.push_back(node->key);
            rangeQueryRec(node->right, a, b, result);
        }
    }

    // 递归销毁函数
    void destroyRec(BSTNode* node) {
        if (!node) return;
        destroyRec(node->left);
        destroyRec(node->right);
        delete node;
    }

public:
    BST() : root(nullptr) {}

    // 插入接口
    void insert(int key) {
        if (contains(key)) return; // 如果已存在，忽略
        root = insertRec(root, key);
    }

    // 检查键是否存在
    bool contains(int key) {
        BSTNode* current = root;
        while (current) {
            if (key == current->key) return true;
            else if (key < current->key) current = current->left;
            else current = current->right;
        }
        return false;
    }

    // 中序遍历接口
    vector<int> inOrder() {
        vector<int> result;
        inOrderRec(root, result);
        return result;
    }

    // 范围查询接口
    vector<int> rangeQuery(int a, int b) {
        vector<int> result;
        // 确保a<=b
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        rangeQueryRec(root, a, b, result);
        return result;
    }

    ~BST() {
        destroyRec(root);
    }
};

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int m;
    fin >> m;

    BST tree;
    string op;
    int key, a, b;

    for (int i = 0; i < m; i++) {
        fin >> op;
        if (op == "I") {
            fin >> key;
            tree.insert(key);
        }
        else if (op == "T") {
            vector<int> res = tree.inOrder();
            if (res.empty()) {
                fout << endl;
            }
            else {
                for (size_t j = 0; j < res.size(); j++) {
                    fout << res[j];
                    if (j < res.size() - 1) fout << " ";
                }
                fout << endl;
            }
        }
        else if (op == "Q") {
            fin >> a >> b;
            vector<int> res = tree.rangeQuery(a, b);
            if (res.empty()) {
                fout << "NULL" << endl;
            }
            else {
                for (size_t j = 0; j < res.size(); j++) {
                    fout << res[j];
                    if (j < res.size() - 1) fout << " ";
                }
                fout << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}