#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

template <typename T1, typename T2>
struct BSTNode                      // 二叉排序树结点类
{
    T1 key;                         // 存放关键字，假设关键字为 T1 类型
    T2 data;                        // 存放数据项，假设数据项为 T2 类型

    BSTNode* lchild;                // 存放左孩子指针
    BSTNode* rchild;                // 存放右孩子指针

    BSTNode(T1 k, T2 d)             // 构造函数
    {
        key = k;
        data = d;
        lchild = rchild = NULL;     // 新建结点默认为叶子结点
    }
};

template <typename T1, typename T2>
class BSTClass                      // 二叉排序树类模板
{
public:
    BSTNode<T1, T2>* r;             // 二叉排序树根结点
    BSTNode<T1, T2>* f;             // 用于临时存放待删除结点的双亲

    BSTClass()                      // 构造函数
    {
        r = NULL;
        f = NULL;
    }

    ~BSTClass()                     // 析构函数
    {
        DestroyBTree(r);            // 调用 DestroyBTree() 函数
        r = NULL;
    }

    void DestroyBTree(BSTNode<T1, T2>* b)  // 释放所有的结点空间
    {
        // PPT 此处省略具体实现
    }


    //插入
    void InsertBST(T1 k, T2 d)          // 插入一个 (k, d) 结点
    {
        r = _InsertBST(r, k, d);
    }

    BSTNode<T1, T2>* _InsertBST(BSTNode<T1, T2>* p, T1 k, T2 d)
        // 在以 p 为根的 BST 中插入关键字为 k 的结点
    {
        if (p == NULL)                  // 原树为空，为根结点
        {
            p = new BSTNode<T1, T2>(k, d);
        }
        else if (k < p->key)
        {
            p->lchild = _InsertBST(p->lchild, k, d);   // 插入到 p 的左子树中
        }
        else if (k > p->key)
        {
            p->rchild = _InsertBST(p->rchild, k, d);   // 插入到 p 的右子树中
        }
        else
        {
            p->data = d;                // 相同关键字，修改 data 域
        }

        return p;
    }

    //创建
    void CreateBST(vector<T1>& a, vector<T2>& b)
        // 由 a 和 b 向量创建一棵二叉排序树
    {
        r = new BSTNode<T1, T2>(a[0], b[0]);     // 创建根结点

        for (int i = 1; i < a.size(); i++)       // 创建其他结点
        {
            InsertBST(a[i], b[i]);               // 插入 (a[i], b[i])
        }
    }

    //查找
    BSTNode<T1, T2>* SearchBST(T1 k)    // 在二叉排序树中查找关键字为 k 的结点
    {
        return _SearchBST(r, k);        // r 为二叉排序树的根结点
    }

    BSTNode<T1, T2>* _SearchBST(BSTNode<T1, T2>* p, T1 k)
        // 被 SearchBST 方法调用
    {
        if (p == NULL)
            return NULL;                // 空树返回 NULL

        if (p->key == k)
            return p;                   // 找到后返回 p

        if (k < p->key)
            return _SearchBST(p->lchild, k);     // 在左子树中递归查找
        else
            return _SearchBST(p->rchild, k);     // 在右子树中递归查找
    }
};
