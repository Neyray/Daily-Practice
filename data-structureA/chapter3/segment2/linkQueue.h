#ifndef LINKQUEUE_H
#define LINKQUEUE_H

//队列的链式存储
//初始：front=rear=NULL
//队空条件：front=rear=NULL
//进队操作：新建节点，rear指向它，之后等于它
//！！！
//特别要注意：只有一个元素进行弹出操作时，需要重置front,rear
//出队操作：取出队首节点，并删除

//没有哨兵节点，front是第一个元素，rear是最后一个元素
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node():next(NULL){}
    Node(T d):data(d),next(NULL){}
};

template <typename T>
class LinkQueue{
public:
    Node<T>* front;
    Node<T>* rear;

    LinkQueue(){
        front=NULL;
        rear=NULL;
    }
    ~LinkQueue(){
        Node<T>* pre=front,*p;

        //非空队列
        if(pre!=NULL){
            //队列只有一个元素
            if(pre==rear)delete pre;
            else{
                p=pre->next;
                while(p!=NULL){
                    delete pre;
                    pre=p;p=p->next;
                }
            }
        }
    }

    bool empty(){
        return rear==NULL;
    }

    bool push(T e){
        Node<T>* p=new Node(e);

        //链表为空的情况
        if(rear==NULL){
            front=rear=p;
        }
        else{
            rear->next=p;
            rear=p;
        }
        return true;
    }

    bool pop(T& e){
        if(rear==NULL)return false;

        Node<T>* p=front;
        //队列中只有一个元素，则弹出后需要重新初始化front,rear
        if(front==rear)front=rear=NULL;
        else{
            front=front->next;//更新队首节点的位置
        }

        e=p->data;
        delete p;
        return true;
    }

    bool gethead(T& e){
        if(rear==NULL)return false;

        e=front->data;
        return true;
    }
};
















#endif