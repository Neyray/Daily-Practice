#ifndef CQUEUE2_H
#define CQUEUE2_H

//循环队列但是采用front+count设计
//不会出现假溢出+哨兵节点
//初始条件：front=0;count=0
//队空条件：count=0
//队满条件：count=maxSize
//进队操作：rear=(rear+1)%maxSize
//出队操作：front=(front+1)%maxSize

//rear指向当前队列的最后一个元素
//front指向当前队列第一个元素的前驱，存储数据(只有在满队列的时候，才有元素)
//当队列满的时候，实际上front=rear
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxSize=100;
template <typename T>
class Cqueue2{
public:
    T* data;
    int front;
    int count;

    Cqueue2(){
        data=new T[maxSize];
        front=0;
        count=0;
    }
    ~Cqueue2(){
        delete[] data;
    }

    bool empty(){
        return count==0;
    }

    bool push(T e){
        if(count==maxSize)return false;

        //rear为队列的尾部元素
        int rear=(front+count)%maxSize;
        rear=(rear+1)%maxSize;
        data[rear]=e;
        count++;

        return true;
    }

    bool pop(T& e){
        if(count==0)return false;
        front=(front+1)%maxSize;
        e=data[front];
        count--;

        return true;
    }

    bool gettop(T& e){
        if(count==0)return false;

        int head=(front+1)%maxSize;
        e=data[head];
        return true;
    }
};















#endif