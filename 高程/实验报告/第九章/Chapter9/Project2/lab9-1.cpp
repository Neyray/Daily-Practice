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
    bool search(const T& key) const;
    void remove(const T& key);
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
bool LinkedList<T>::search(const T& key) const {
    Node<T>* temp = head;
    while (temp) {
        if (temp->getData() == key) {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T& key) {
    while (head && head->getData() == key) {
        Node<T>* toDelete = head;
        head = head->getNext();
        delete toDelete;
    }
    if (!head) return;

    Node<T>* current = head;
    while (current->getNext()) {
        if (current->getNext()->getData() == key) {
            Node<T>* toDelete = current->getNext();
            current->setNext(toDelete->getNext());
            delete toDelete;
        }
        else {
            current = current->getNext();
        }
    }
}

template<typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* toDelete = head;
        head = head->getNext();
        delete toDelete;
    }
}

int main() {
    LinkedList<int> list;
    int val;
    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    cout << "Linked list contents: ";
    list.display();

    int key;
    cout << "Enter a value to search and delete: ";
    cin >> key;
    if (list.search(key)) {
        list.remove(key);
        cout << "After deletion, list contents: ";
        list.display();
    }
    else {
        cout << "Value not found." << endl;
    }

    list.clear();
    return 0;
}