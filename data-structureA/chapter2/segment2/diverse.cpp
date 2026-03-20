#include "LinkList.h"
#include <iostream>
using namespace std;

template <typename T>
void diverse(LinkList<T>& L,LinkList<T>& A,LinkList<T>& B){
    //A为偶数位0,2,4；尾插法建表
    //B为奇数位1,3,5；头插法建表

    //在一次循环中移动两次指针
    LinkNode<T>* p=L.head->next;
    LinkNode<T>* r1=A.head;
    //LinkNode* r2=B.head;
    while(p!=NULL){
        //先处理A
        r1->next=p;
        r1=p;   //A用r1来进行尾插法
        p=p->next;

        //执行第一次移动后轮到B
        if(p!=NULL){
            //先存储p的后继节点
            LinkNode<T>* q=p->next;
            p->next=B.head->next;
            B.head->next=p;
            p=q;   //实际上进行了一次移动指针操作
        }
    }
    r1->next=NULL;
    L.head->next = NULL; // 建议：原表 L 置空
}