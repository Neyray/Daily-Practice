#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class OrderedList {
public:
    Node* head;

    OrderedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next && temp->next->data < val) {
                temp = temp->next;
            }
            if (temp->next && temp->next->data == val) {
                return; // ШЅжи
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void print() {
        Node* temp = head;
        if (!temp) {
            cout << "" << endl;
            return;
        }
        while (temp) {
            cout << temp->data;
            if (temp->next) {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << " " << endl;
    }
};

int main() {
    OrderedList A, B, C;
    string line;
    int num;

    getline(cin, line);
    stringstream ssA(line);
    while (ssA >> num) {
        A.insert(num);
    }

    getline(cin, line);
    stringstream ssB(line);
    while (ssB >> num) {
        B.insert(num);
    }

    Node* p = A.head;
    Node* q = B.head;

    while (p && q) {
        if (p->data < q->data) {
            C.insert(p->data);
            p = p->next;
        }
        else if (p->data > q->data) {
            C.insert(q->data);
            q = q->next;
        }
        else {
            C.insert(p->data);
            p = p->next;
            q = q->next;
        }
    }

    while (p) {
        C.insert(p->data);
        p = p->next;
    }

    while (q) {
        C.insert(q->data);
        q = q->next;
    }

    C.print();
    return 0;
}