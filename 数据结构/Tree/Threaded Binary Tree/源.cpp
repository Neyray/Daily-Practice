#include <iostream>
#include <stack>
using namespace std;

struct ThreadNode {
    int data;
    ThreadNode* lchild;
    ThreadNode* rchild;
    int ltag;  // 0 表示真正的左子指针，1 表示前驱线索指针
    int rtag;  // 0 表示真正的右子指针，1 表示后继线索指针

    ThreadNode(int val)
        : data(val), lchild(nullptr), rchild(nullptr), ltag(0), rtag(0)
    {
    }
};

// 构建示例二叉树：
//        1
//      /   \
//     2     3
//    / \   /
//   4   5 6
ThreadNode* buildSample() {
    auto* root = new ThreadNode(1);
    root->lchild = new ThreadNode(2);
    root->rchild = new ThreadNode(3);
    root->lchild->lchild = new ThreadNode(4);
    root->lchild->rchild = new ThreadNode(5);
    root->rchild->lchild = new ThreadNode(6);
    return root;
}

// —— 前序线索化核心函数 ——
void preThreading(ThreadNode* cur, ThreadNode*& pre) {
    if (!cur) return;
    if (!cur->lchild) {
        cur->ltag = 1;
        cur->lchild = pre;
    }
    if (pre && !pre->rchild) {
        pre->rtag = 1;
        pre->rchild = cur;
    }
    pre = cur;
    if (cur->ltag == 0) preThreading(cur->lchild, pre);
    if (cur->rtag == 0) preThreading(cur->rchild, pre);
}

void createPreThread(ThreadNode* root) {
    ThreadNode* pre = nullptr;
    preThreading(root, pre);
    if (pre && pre->rtag == 1) pre->rchild = nullptr;
}

void preOrderTraverse(ThreadNode* root) {
    ThreadNode* p = root;
    while (p) {
        cout << p->data << " ";
        p = (p->ltag == 0 ? p->lchild : p->rchild);
    }
}

// —— 中序线索化核心函数 ——
void inThreading(ThreadNode* cur, ThreadNode*& pre) {
    if (!cur) return;
    inThreading(cur->lchild, pre);
    if (!cur->lchild) {
        cur->ltag = 1;
        cur->lchild = pre;
    }
    if (pre && !pre->rchild) {
        pre->rtag = 1;
        pre->rchild = cur;
    }
    pre = cur;
    inThreading(cur->rchild, pre);
}

void createInThread(ThreadNode* root) {
    ThreadNode* pre = nullptr;
    inThreading(root, pre);
    if (pre) { pre->rtag = 1; pre->rchild = nullptr; }
}

void inOrderTraverse(ThreadNode* root) {
    ThreadNode* p = root;
    while (p && p->ltag == 0) p = p->lchild;
    while (p) {
        cout << p->data << " ";
        if (p->rtag == 1) p = p->rchild;
        else {
            p = p->rchild;
            while (p && p->ltag == 0) p = p->lchild;
        }
    }
}

// —— 后序遍历（递归版本，避开线索化破坏） ——
void postOrderTraverse(ThreadNode* root) {
    if (!root) return;
    if (root->ltag == 0) postOrderTraverse(root->lchild);
    if (root->rtag == 0) postOrderTraverse(root->rchild);
    cout << root->data << " ";
}

int main() {
    // 中序示例
    {
        ThreadNode* root = buildSample();
        createInThread(root);
        cout << "InOrder:  ";
        inOrderTraverse(root);
        cout << "\n";
    }

    // 前序示例
    {
        ThreadNode* root = buildSample();
        createPreThread(root);
        cout << "PreOrder: ";
        preOrderTraverse(root);
        cout << "\n";
    }

    // 后序示例（采用递归，避免线索化干扰）
    {
        ThreadNode* root = buildSample();
        cout << "PostOrder:";
        postOrderTraverse(root);
        cout << "\n";
    }

    return 0;
}



