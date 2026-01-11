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
        node* mhead = new node;
        mhead->data = -1;
        tail = NULL;
        mhead->next = tail;
        head = mhead;
        size = 0;
    }

    void headinsert(int n) {
        node* temp = new node;
        temp->data = n;
        temp->next = NULL;
        if (tail == NULL) {
            head->next = temp;
            tail = temp;
            return;
        }
        temp->next = head->next;
        head->next = temp;
    }

    void tailinsert(int n) {
        node* temp = new node;
        temp->data = n;
        temp->next = NULL;
        if (tail == NULL) {
            tail = temp;
            head->next = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void myprint() {
        node* current = head->next;
        while (current != NULL) {
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
    stringstream ss1(line1);
    stringstream ss2(line2);
    while (ss1 >> num) {
        l1.tailinsert(num);
    }
    while (ss2 >> num) {
        l2.tailinsert(num);
    }
    list c;
    node* p = l1.head->next;
    node* q = l2.head->next;
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            c.headinsert(p->data);
            p = p->next;
        }
        else if (p->data > q->data) {
            c.headinsert(q->data);
            q = q->next;
        }
        else {
            c.headinsert(p->data);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL || q != NULL) {
        if (q == NULL) {
            c.headinsert(p->data);
            p = p->next;
        }
        else {
            c.headinsert(q->data);
            q = q->next;
        }
    }
    c.myprint();
    return 0;
}