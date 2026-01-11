#ifndef QUEUE_H
#define QUEUE_H

#include "Link.h"
#include <stdexcept> // 用于异常处理
#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
    LinkedList<T> list;
public:
    void enqueue(const T& item);
    T dequeue();
    bool isEmpty() const;
    void display();
};

template<typename T>
void Queue<T>::enqueue(const T& item) {
    list.insertAtEnd(item);
}

template<typename T>
T Queue<T>::dequeue() {
    if (list.isEmpty()) {
        throw underflow_error("Queue is empty");
    }
    // 获取头节点数据
    Node<T>* head = list.getHead();
    T data = head->getData();
    list.removeFront();
    return data;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return list.isEmpty();
}

template<typename T>
void Queue<T>::display() {
    list.display();
}

#endif