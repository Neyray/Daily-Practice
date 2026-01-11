#ifndef LINK_H
#define LINK_H

#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void insertAtEnd(const T& item);
    void display() const;
    void concatenate(LinkedList<T>& other);

    // 新增方法用于队列实现
    bool isEmpty() const;
    Node<T>* getHead() const;
    void removeFront();
    void clear();
};

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void LinkedList<T>::insertAtEnd(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    if (!head) {
        head = newNode;
    }
    else {
        Node<T>* temp = head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template<typename T>
void LinkedList<T>::display() const {
    Node<T>* temp = head;
    while (temp) {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

template<typename T>
void LinkedList<T>::concatenate(LinkedList<T>& other) {
    if (!head) {
        head = other.head;
    }
    else {
        Node<T>* temp = head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(other.head);
    }
    other.head = nullptr;
}

// 新增方法实现
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

template<typename T>
void LinkedList<T>::removeFront() {
    if (!head) return;
    Node<T>* toDelete = head;
    head = head->getNext();
    delete toDelete;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* toDelete = head;
        head = head->getNext();
        delete toDelete;
    }
}

#endif