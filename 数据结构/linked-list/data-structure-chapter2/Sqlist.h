#ifndef SQLIST_H
#define SQLIST_H

template <typename T>
class Sqlist {
public:
    //构造函数
    Sqlist(int initial_capacity = 10);
    //析构函数
    ~Sqlist();
    //1.改变顺序表的容量
    void recap(int newcap);

    //2.整体建立顺序表
    void CreateList(T a[], int n);

    //3.复制构造函数
    Sqlist(const Sqlist<T>& s);

    //4.将元素e添加到顺序表末尾
    void Add(T e);

    //5.求顺序表的长度
    int Getlength();

    //6.求顺序表中序号为i的元素值
    bool GetElem(int i, T& e);

    //7.设置顺序表中序号为i的元素值
    bool SetElem(int i, T e);

    //8.求顺序表中第一个值为e的元素的序号
    int GetNo(T e);

    //9.在顺序表中插入e作为第i个元素
    bool Insert(int i, T e);

    //10.在顺序表删除第i个元素
    bool Delete(int i);

    //11.输出顺序表中的所有元素
    void DispList();

    T* data;
    int capacity;
    int length;
};

#include "Sqlist.cpp"  // 包含实现文件

#endif // SQLIST_H
