#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class list {
public:
    node* head;
    node* tail;
    int size;

    list() {
        head = new node;
        head->data = -1;
        head->next = nullptr;
        tail = nullptr;
        size = 0;
    }

    void tailinsert(int n) {
        node* temp = new node;
        temp->data = n;
        temp->next = nullptr;
        if (tail == nullptr) {
            tail = temp;
            head->next = temp;
        }
        else {
            tail->next = temp;
            //更新tail的位置
            tail = temp;
        }
        size++;
    }

    void myprint() {
        node* current = head->next;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    list l1, l2;
    int num;
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss1(line1), ss2(line2);
    while (ss1 >> num) {
        l1.tailinsert(num);
    }
    while (ss2 >> num) {
        l2.tailinsert(num);
    }
    list c;
    node* p = l1.head->next;
    node* q = l2.head->next;
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            c.tailinsert(p->data);
            p = p->next;
        }
        else if (p->data > q->data) {
            q = q->next;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    while (p != nullptr) {
        c.tailinsert(p->data);
        p = p->next;
    }
    c.myprint();
    return 0;
}