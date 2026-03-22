//找出两个链表中第k小的值
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

Node* buildList(int n) {
    Node* head = new Node();
    Node* p = head;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        p->next = new Node(num);
        p = p->next;
    }
    return head;
}

int main() {
    int m, n, k; cin >> m >> n >> k;
    Node* ahead = buildList(m);
    Node* bhead = buildList(n);

    Node* p = ahead->next;
    Node* q = bhead->next;
    int cnt = 0;

    while (p != nullptr && q != nullptr) {
        cnt++;
        if (p->data <= q->data) {
            if (cnt == k) { cout << p->data; return 0; }
            p = p->next;
        } else {
            if (cnt == k) { cout << q->data; return 0; }
            q = q->next;
        }
    }
    // 一个链表用完了，继续跑剩余的
    while (p != nullptr) {
        cnt++;
        if (cnt == k) { cout << p->data; return 0; }
        p = p->next;
    }
    while (q != nullptr) {
        cnt++;
        if (cnt == k) { cout << q->data; return 0; }
        q = q->next;
    }
    return 0;
}