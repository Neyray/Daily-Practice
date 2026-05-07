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

//建立先序线索二叉树

// 核心递归函数：注意第二个参数是 指针的引用，保证全过程共享同一个 pre
void PreThreading(ThreadNode* p, ThreadNode*& pre) {
    if (p == NULL) return;

    // 1. 处理当前节点 p 的左线索（找前驱）
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    
    // 2. 处理前驱节点 pre 的右线索（找后继）
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    
    // 3. 更新 pre 为当前节点
    pre = p;
    
    // 4. 递归处理左右子树
    // 【致命易错点】：先序是“根左右”，刚才 p->lchild 可能已经被线索化指向了 pre (ltag 变为了 1)。
    // 如果不加 p->ltag == 0 的判断，直接 PreThreading(p->lchild)，就会无限回头找前驱，导致死循环爆栈！
    if (p->ltag == 0) {
        PreThreading(p->lchild, pre);
    }
    if (p->rtag == 0) {
        PreThreading(p->rchild, pre);
    }
}

// 包装函数：供外部调用，初始化 pre
void CreatePreThread(ThreadNode* root) {
    ThreadNode* pre = NULL; // 局部变量，但在递归中被引用传递
    if (root != NULL) {
        PreThreading(root, pre);
        
        // 【注意】：遍历结束后，最后一个节点的 rchild 肯定是 NULL，别忘了把它的 rtag 设为 1
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
    }
}


//遍历先序线索二叉树
void PreOrderTraversal(ThreadNode* root) {
    ThreadNode* p = root;
    while (p) {
        cout << p->data;        // 先访问根
        
        // 决定下一个走哪：优先左孩子，没有就走右孩子（或右线索）
        if (p->ltag == 0) {
            p = p->lchild;      // 有左孩子就去左孩子（先序下一个就是它）
        } else {
            p = p->rchild;      // 没左孩子，就走 rchild（可能是右孩子，也可能是后继线索）
        }
    }
}