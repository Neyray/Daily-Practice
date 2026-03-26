#ifndef CQUEUE_H
#define CQUEUE_H

//循环队列，大小固定，不会出现假溢出
//但是会出现一个位置的哨兵节点（不能放数据）
//初始：front=rear=0
//队空条件：rear==front
//队满条件：(rear+1)%maxSize==front
//进队：rear=(rear+1)%maxSize
//出队：front=(front+1)%maxSize

//rear指向当前队列的最后一个元素
//front指向当前队列第一个元素的前驱，实际上不储存任何数据
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int maxSize=100;
template <typename T>
class Cqueue{
public:
    T* data;
    int front,rear;

    Cqueue(){
        data=new T[maxSize];
        front=rear=0;
    }
    ~Cqueue(){
        delete[] data;
    }

    bool empty(){
        return front==rear;
    }

    bool push(T e){
        if((rear+1)%maxSize==front)return false;

        rear=(rear+1)%maxSize;
        data[rear]=e;
        return true;
    }

    bool pop(T& e){
        if(front==rear)return false;

        front=(front+1)%maxSize;
        e=data[front];
        return true;
    }

    bool gethead(T& e){
        if(front==rear)return false;

        //front的指向不能轻易改变
        int head=(front+1)%maxSize;
        e=data[head];
        return true;
    }
};

#endif