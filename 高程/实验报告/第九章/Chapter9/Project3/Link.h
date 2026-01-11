#pragma once
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
};

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
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
    other.head = nullptr; // 防止其他链表被析构时释放节点
}

#endif