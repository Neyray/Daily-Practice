#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ThreadNode {
    char data;
    ThreadNode *lchild, *rchild;
    //遍历的第一个ltag=1，最后一个rtag=1
    int ltag, rtag; // 0: 孩子, 1: 线索

    ThreadNode(char ch) : data(ch), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {}
};

ThreadNode* pre = NULL; // 全局变量，记录刚刚访问过的节点

//把普通二叉树线索化
void InThreading(ThreadNode* p) {
    if (p) {
        InThreading(p->lchild); // 递归左子树
        
        if (!p->lchild) {       // 左空，建立前驱线索
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && !pre->rchild) { // 前驱节点的右空，建立后继线索
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;                // 保持 pre 指向 p，为什么？因为已经处理完了左子树，现在要把pre更新到根节点，方便之后的右子树递归更新
        
        InThreading(p->rchild); // 递归右子树
    }
}

// 无栈、无递归中序遍历
void InOrderTraversal(ThreadNode* root) {
    ThreadNode* p = root;
    while (p) {
        while (p->ltag == 0) p = p->lchild; // 1.一路向左到第一个节点
        cout << p->data;                     // 2.访问

        //这一步是“左->根”的操作，左是没有右节点的节点
        while (p->rtag == 1 && p->rchild) { // 3.沿后继线索连续访问
            p = p->rchild;
            cout << p->data;//输出“根”
        }
        //“根->右”的操作
        //此时p->rtag=0，说明存在右子树，那么就需要到右子树处理
        p = p->rchild; // 4.走到右子树根，回到1
    }
}