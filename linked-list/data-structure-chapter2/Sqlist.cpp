#include "Sqlist.h"
#include <iostream>
using namespace std;

template <typename T>
Sqlist<T>::Sqlist(int initial_capacity) {
    capacity = initial_capacity;
    data = new T[capacity];
}

template <typename T>
Sqlist<T>::~Sqlist() {
    delete[] data;
}

//1.改变顺序表的容量
template <typename T>
void Sqlist<T>::recap(int newcap) {
    if (newcap <= 0) return;
    T* olddata = data;
    data = new T[newcap];
    for (int i = 0; i < capacity && i < newcap; ++i) {
        data[i] = olddata[i];
    }
    capacity = newcap;
    delete[] olddata;
}

//2.整体建立顺序表
template <typename T>
void Sqlist<T>::CreateList(T a[], int n) {                     //用数组a中的元素整体建立顺序表
    for (int i = 0; i < n; i++) {
        if (length == capacity) {
            recap(2 * length);
        }
        data[length] = a[i];
        length++;
    }
}

//3.复制构造函数
template <typename T>
Sqlist<T>::Sqlist(const Sqlist<T>& s) {
    capacity = s.capacity;
    length = s.length;
    data = new T[capacity];
    for (int i = 0; i < length; ++i) {
        data[i] = s->data[i];
    }
}

//4.将元素e添加到顺序表末尾
template <typename T>
void Sqlist<T>:: Add(T e) {
    if (capacity == length) {
        recap(2 * length);
    }
    data[length] = e;
    length++;
}

//5.求顺序表的长度
template <typename T>
int Sqlist<T>::Getlength() {
    return length;
}

//6.求顺序表中序号为i的元素值
template <typename T>
bool Sqlist<T>::GetElem(int i, T& e) {
    if (i < 0 || i >= length)
        return false;
    e = data[i];
    return true;
}

//7.设置顺序表中序号为i的元素值
template <typename T>
bool Sqlist<T>::SetElem(int i, T e) {
    if (i < 0 || i >= length)
        return false;
    data[i] = e;
    return true;
}

//8.求顺序表中第一个值为e的元素的序号
template <typename T>
int Sqlist<T>::GetNo(T e) {
    int i = 0;
    //查找元素e
    while (i < length && data[i] != e) {
        i++;
    }
    if (i >= length)
        return -1;
    else
        return i;
}

//9.在顺序表中插入e作为第i个元素
template <typename T>
bool Sqlist<T>::Insert(int i, T e) {
    if (i<0 || i>length)
        return false;
    if (length == capacity)
        recap(2 * length);
    //将data[i]及之后的元素后移一个位置
    for (int j = length; j > i; j--) {
        data[j] = data[j - 1];
    }
}

//10.在顺序表删除第i个元素
template <typename T>
bool Sqlist<T>::Delete(int i) {
    if (i < 0 || i >= length)
        return false;
    for (int j = i; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    if (capacity > initialcap && length <= capacity / 4)
        recap(capacity / 2);
    return true;
}

//11.输出顺序表中的所有元素
template <typename T>
void Sqlist<T>::DispList() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}