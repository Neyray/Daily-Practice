#include "LinkList.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
LinkList<T> reverse(LinkList<T>& list){
    if (list.head->next == NULL || list.head->next->next == NULL) 
        return list; // 空表或只有一个元素，无需翻转
    //对链表List进行翻转操作
    //直接在list上进行操作
    LinkNode<T>* p=list.head;
    p=p->next;

    list.head->next=NULL;
    while(p!=NULL){
        //q用来暂存p的下一个节点
        LinkNode<T>* q=p->next;
        p->next=list.head->next;
        list.head->next=p;
        p=q;
    }
    return list;
}