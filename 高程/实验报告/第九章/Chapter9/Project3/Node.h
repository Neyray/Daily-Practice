#pragma once
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(const T& item, Node<T>* ptr = nullptr);
    T getData() const;
    Node<T>* getNext() const;
    void setData(const T& item);
    void setNext(Node<T>* ptr);
};

template<typename T>
Node<T>::Node(const T& item, Node<T>* ptr) : data(item), next(ptr) {}

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template<typename T>
void Node<T>::setData(const T& item) {
    data = item;
}

template<typename T>
void Node<T>::setNext(Node<T>* ptr) {
    next = ptr;
}

#endif