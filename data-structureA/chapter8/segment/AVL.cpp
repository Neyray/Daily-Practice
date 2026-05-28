#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

template <typename T1, typename T2>
struct AVLNode                      // AVL 树结点类模板
{
    T1 key;                         // 关键字 k
    T2 data;                        // 关键字对应的值 d

    int ht;                         // 当前结点的子树高度

    AVLNode* lchild;
    AVLNode* rchild;                // 左右指针

    AVLNode(T1 k, T2 d)             // 构造函数，新建结点均为叶子，高度为 1
    {
        key = k;
        data = d;
        ht = 1;                     // 当前结点的子树高度
        lchild = rchild = NULL;
    }
};

template <typename T1, typename T2>
class AVLTree                       // AVL 树类模板
{
    AVLNode<T1, T2>* r;             // AVL 的根结点

public:
    AVLTree() : r(NULL) {}          // 构造函数

    int getht(AVLNode<T1, T2>* p)   // 返回结点 p 的子树高度
    {
        if (p == NULL)
            return 0;

        return p->ht;
    }

    // LL型
    AVLNode<T1, T2>* right_rotate(AVLNode<T1, T2>* a)
        // 以结点 a 为根做右旋转
    {
        AVLNode<T1, T2>* b = a->lchild;

        a->lchild = b->rchild;
        b->rchild = a;

        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;   // 更新 A 结点的高度
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;   // 更新 B 结点的高度

        return b;
    }

    AVLNode<T1, T2>* LL(AVLNode<T1, T2>* a)     
    {
        return right_rotate(a);
    }


    //RR型
    AVLNode<T1, T2>* left_rotate(AVLNode<T1, T2>* a)
        // 以结点 a 为根做左旋转
    {
        AVLNode<T1, T2>* b = a->rchild;

        a->rchild = b->lchild;
        b->lchild = a;

        a->ht = max(getht(a->rchild), getht(a->lchild)) + 1;   // 更新 A 结点的高度
        b->ht = max(getht(b->rchild), getht(b->lchild)) + 1;   // 更新 B 结点的高度

        return b;
    }

    //LR型
    AVLNode<T1, T2>* LR(AVLNode<T1, T2>* a)     
    {
        AVLNode<T1, T2>* b = a->lchild;

        a->lchild = left_rotate(b);             // 结点 b 左旋

        return right_rotate(a);                 // 结点 a 右旋
    }

    //RL型
    AVLNode<T1, T2>* RL(AVLNode<T1, T2>* a)     
    {
        AVLNode<T1, T2>* b = a->rchild;

        a->rchild = right_rotate(b);            // 结点 b 右旋

        return left_rotate(a);                  // 结点 a 左旋
    }
};