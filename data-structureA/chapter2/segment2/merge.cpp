#include "LinkList.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void merge(LinkList<T>& A,LinkList<T>& B,LinkList<T>& C){
    LinkNode<T>* p=A.head->next;
    LinkNode<T>* q=B.head->next;
    LinkNode<T>* r=C.head;
    while(q!=NULL && p!=NULL){
        if(p->data <= q->data){
            r->next=p;
            r=p;
            p=p->next;
        }
        else{
            r->next=q;
            r=q;
            q=q->next;
        }
    }

    while(p!=NULL){
        r->next=p;
        r=p;
        p=p->next;
    }
    while(q!=NULL){
        r->next=q;
        r=q;
        q=q->next;
    }
    r->next=NULL;
}