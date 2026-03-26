#ifndef QUEUE_H
#define QUEUE_H

//非循环队列
//初始时，front=rear=-1
//队空条件，front==rear
//队满条件，rear=maxSize-1
//进队操作，rear+=1,将元素放在该位置
//出队操作，front+=1，取出该位置的元素
//会出现伪溢出

//rear指向当前队列的最后一个元素
//front指向当前队列第一个元素的前驱，实际上不储存任何数据
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxSize=100;
template <typename T>
class Queue{
public:
    T* data;
    int front,rear;

    Queue(){
        data=new T[maxSize];
        front=rear=-1;
    }
    ~Queue(){
        delete[]data;
    }

    bool empty(){
        return front==rear;
    }

    bool push(T e){
        if(rear==maxSize-1)return false;
        rear+=1;
        data[rear]=e;
        return true;
    }

    bool pop(T& e){
        if(rear==front)return false;
        front+=1;
        e=data[front];
        return true;
    }

    bool gethead(T& e){
        if(rear==front)return false;

        //front指的是头节点之前的一个位置，相当于哨兵节点，除了pop操作不能随便移动！！！
        int head=front+1;
        e=data[head];
        return true;
    }
};

#endif