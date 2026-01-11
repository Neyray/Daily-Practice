/*
【问题描述】
从键盘输入10个整数，用这些整数值作为结点数据，生成一个链表，按顺序输出链表中结点的数值。
然后从键盘输入一个待查找整数，在链表中查找该整数，若找到则删除该整数所在的结点
（如果出现多次，全部删除），然后输出删除结点以后的链表。

该题重点在于自定义创建链表函数CreateList()，遍历链表函数TraverseList(pNode pHead)，
删除链表节点函数Del_Node(pNode pHead,int del)。main函数需要调用以上函数实现题目要求，
因此提供基本程序框架作为约束和提示，请独自补充main函数和自定义函数实现文件的编号。
*/

#include <iostream>
#include <cstdlib>
using namespace std;

//保留了C语言的习惯，C++不需要起别名也可以直接使用
typedef struct node {
    int member;
    node* pNext;
} Node, * pNode;

pNode CreateList() {
    pNode pHead = NULL;  // ① 头指针，指向链表的第一个节点
    pNode pTail = NULL;  // ② 尾指针，指向链表的最后一个节点
    int data;

    for (int i = 0; i < 10; i++) {  // ③ 循环10次，创建10个节点
        cin >> data;  // ④ 输入数据

        // ⑤ 创建新节点
        pNode pNew = (pNode)malloc(sizeof(Node));
        pNew->member = data;      // 把数据存到新节点
        pNew->pNext = NULL;       // 新节点的next指针暂时指向空

        // ⑥ 判断是否是第一个节点
        if (pHead == NULL) {
            pHead = pNew;  // 第一个节点既是头也是尾
            pTail = pNew;
        }
        else {
            // ⑦ 不是第一个节点，接到链表尾部
            pTail->pNext = pNew;  // 原来的尾节点指向新节点
            pTail = pNew;         // 尾指针移动到新节点
        }
    }

    return pHead;  // ⑧ 返回头指针
}

void TraverseList(pNode pHead) {
    pNode p = pHead;
    while (p != NULL) {
        cout << p->member << " ";
        p = p->pNext;
    }
    cout << endl;
}

int Del_Node(pNode pHead, int del) {
    if (pHead == NULL) return 0;

    int count = 0;
    pNode p = pHead;
    pNode pre = NULL;

    while (p != NULL) {
        if (p->member == del) {
            count++;
            if (pre == NULL) {
                pHead = p->pNext;
                free(p);
                p = pHead;
            }
            else {
                pre->pNext = p->pNext;
                free(p);
                p = pre->pNext;
            }
        }
        else {
            pre = p;
            p = p->pNext;
        }
    }

    return count;
}

int main() {
    pNode pHead = NULL;
    int num;
    int return_val = -1;

    pHead = CreateList();

    cout << "创建的链表为：";
    TraverseList(pHead);

    cout << "请输入要删除节点的值：";
    cin >> num;

    while (return_val != 0) {
        return_val = Del_Node(pHead, num);
    }

    cout << "操作完成后的数据是：";
    TraverseList(pHead);

    return 0;
}