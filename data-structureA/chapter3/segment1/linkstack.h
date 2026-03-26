#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node():next(NULL){}
    Node(T d):data(d),next(NULL){}
};

template <typename T>
class liststack{
public:
    Node<T>* head;

    liststack(){
        head=new Node();
    }
    ~liststack(){
        Node<T>* p=head;
        Node<T>* q;
        while(p!=NULL){
            q=p->next;
            delete p;
            p=q;
        }
    }

    bool empty(){
        return head->next==NULL;
    }

    bool push(T e){
        Node<T>* s=new Node(e);
        //！！！
        //采用头插法，head之后的节点就是栈顶
        //！！！
        s->next=head->next;
        head->next=s;
        return true;
    }

    bool pop(T& e){
        if(head->next==NULL)return false;

        Node<T>* p=head->next;e=p->data;
        head->next=p->next;
        delete p;

        return true;
    }

    bool gettop(T& e){
        if(head->next==NULL)return false;
        e=head->next->data;
        return true;
    }
};

#endif