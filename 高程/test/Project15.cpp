/*
【问题描述】
从键盘输入10个整数，用这些整数值作为结点数据，生成一个链表，按顺序输出链表中结点的数值。
然后从键盘输入一个待查找整数，在链表中查找该整数，若找到则删除该整数所在的结点
（如果出现多次，全部删除），然后输出删除结点以后的链表。

链表建造在main函数调用CreateList()，遍历链表需要调用函数TraverseList(pNode pHead)，
删除链表节点调用函数Del_Node(pNode pHead,int del)。main函数需要调用以上函数实现题目要求，
因此提供基本程序框架作为约束和提示，请独自补充main函数和自定义函数实现文件的编号。
*/

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
    int member;
    struct node* pNext;
} Node, * pNode;

pNode CreateList() {
    pNode pHead = NULL;
    pNode pTail = NULL;
    int data;

    for (int i = 0; i < 10; i++) {
        cin >> data;
        pNode pNew = (pNode)malloc(sizeof(Node));
        pNew->member = data;
        pNew->pNext = NULL;

        if (pHead == NULL) {
            pHead = pNew;
            pTail = pNew;
        }
        else {
            pTail->pNext = pNew;
            pTail = pNew;
        }
    }

    return pHead;
}

void TraverseList(pNode pHead) {
    pNode p = pHead;
    while (p != NULL) {
        cout << p->member << endl;
        p = p->pNext;
    }
}

pNode Del_Node(pNode pHead, int del) {
    while (pHead != NULL && pHead->member == del) {
        pNode temp = pHead;
        pHead = pHead->pNext;
        free(temp);
    }

    if (pHead == NULL) return NULL;

    pNode p = pHead;
    while (p->pNext != NULL) {
        if (p->pNext->member == del) {
            pNode temp = p->pNext;
            p->pNext = p->pNext->pNext;
            free(temp);
        }
        else {
            p = p->pNext;
        }
    }

    return pHead;
}

int main() {
    pNode pHead = NULL;
    int num;

    pHead = CreateList();

    TraverseList(pHead);

    cin >> num;

    pHead = Del_Node(pHead, num);

    TraverseList(pHead);

    return 0;
}