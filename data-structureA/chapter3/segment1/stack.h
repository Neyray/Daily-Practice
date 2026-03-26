#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;


int maxSize=5;

template <typename T>
class SqStack{
public:
    T* data;
    int top;

    SqStack(){
        data=new T[maxSize];
        top=-1;
    }
    ~SqStack(){
        delete[] data;
    }

    bool empty(){
        return top==-1;
    }

    bool push(T e){
        if(top==maxSize-1)return false;
        top++;
        data[top]=e;
        return true;
    }

    bool pop(T& e){
        if(top==-1)return false;
        e=data[top];
        top--;
        return true;
    }

    bool gettop(T& e){
        if(top==-1)return false;
        e=data[top];
        return true;
    }
};

#endif