#ifndef SQLIST_H
#define SQLIST_H

#include <iostream>
using namespace std;

const int initcap = 5;      //顺序表的初始容量

template <typename T>
class SqList{
public:
    T* data;
    int capacity;//顺序表的容量（可能会改变）
    int length;//顺序表包含的元素个数

    //构造函数
    SqList(){
        data=new T[initcap];
        capacity=initcap;
        length=0;
    }
    //析构函数
    ~SqList(){
        delete[]data;
    }

    //扩容
    void recap(int newCapacity){
        T* olddata=data;
        //T* data = new T[newCapacity]; // 错误！这定义了一个局部变量data，覆盖了类成员data
        data=new T[newCapacity];
        capacity=newCapacity;

        for(int i=0;i<length;++i){
            data[i]=olddata[i];
        }
        delete[]olddata;
    }

    //添加元素
    void add(T e){
        if(length==capacity){
            recap(2*capacity);  //将容量扩大一倍
        }
        data[length]=e;
        length++;
    }

    //在特定位置插入元素
    void insert(int i,T e){
        if(length==capacity){
            recap(2*capacity);
        }
        for(int j=length-1;j>=i;--j){
            data[j+1]=data[j];
        }
        data[i]=e;
        length++;
    }

    //在特定位置删除元素,i为下标
    void deleteElem(int i){
        for(int j=i;j<=length-2;++j){
            data[j]=data[j+1];
        }
        length--;
    }

    void display(){
        for(int i=0;i<length;++i){
            cout<<data[i]<<" ";
        }
    }
};

#endif