//循环链栈，只有一个尾结点rear，代表栈底
#ifndef CLINKSTACK_H
#define CLINKSTACK_H

//！！！
//没有哨兵节点,rear也存储数据
//！！！
#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node():next(NULL){}
    Node(T d):data(d),next(NULL){}
};

template <typename T>
class cliststack{
public:
    Node<T>* rear;

    cliststack(){
        //！！！
        //不用哨兵节点的构造方法！！！
        //否则使用new Node
        //！！！
        rear=NULL;
    }
    ~cliststack(){
        //这里的rear不是哨兵节点！！！
        if(rear==NULL)return ;
        Node<T>* pre=rear;
        Node<T>* p=rear->next;
        while(p!=rear){
            delete pre;
            pre=p;
            p=p->next;
        }
        delete pre;   
    }

    bool empty(){
        return rear==NULL;
    }

    bool push(T e){
        Node<T>* s=new Node(e);
        //如果链表现在是空
        if(rear==NULL){
            rear=s;
            rear->next=rear;
        }
        else{
            s->next=rear->next;
            rear->next=s;
        }
        return true;
    }

    bool pop(T& e){
        if(rear==NULL)return false;

        Node<T>* p=rear->next;
        e=p->data;
        
        //只有一个元素
        //要将rear置为NULL！！！
        if(p==rear){
            rear=NULL;
        }
        else{
            rear->next=p->next;
        }
        delete p;
        return true;
    }

    bool gettop(T& e){
        if(rear==NULL)return false;
        e=rear->next->data;
        return true;
    }

    T bottom(){
        return rear->data;
    }
};





#endif