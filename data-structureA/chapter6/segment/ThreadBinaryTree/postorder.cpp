#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ThreadNode {
    char data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag; // 0: 孩子, 1: 线索

    ThreadNode(char ch) : data(ch), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {}
};

//建立后序线索二叉树

void PostThreading(ThreadNode* p, ThreadNode*& pre) {
    if (p == NULL) return;

    // 1. 先递归左右子树
    PostThreading(p->lchild, pre);
    PostThreading(p->rchild, pre);

    // 2. 最后处理根节点
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    
    // 3. 更新 pre
    pre = p;
}

// 包装函数
void CreatePostThread(ThreadNode* root) {
    ThreadNode* pre = NULL;
    if (root != NULL) {
        PostThreading(root, pre);
        // 后序遍历的最后一个节点一定是整棵树的根节点，它的 rchild 本来就是 NULL，可以不强制处理 rtag，但为了统一规范加上也没错。
        if (pre->rchild == NULL) {
            pre->rtag = 1; 
        }
    }
}