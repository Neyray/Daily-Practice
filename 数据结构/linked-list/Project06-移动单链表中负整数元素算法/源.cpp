#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* buildList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

Node* rearrangeList(Node* head) {
    Node negDummy(-1);
    Node nonNegDummy(-1);
    Node* negTail = &negDummy;
    Node* nonNegTail = &nonNegDummy;

    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        //断开当前节点与下一个节点的连接，防止后续不小心把原链表连接回去
        current->next = nullptr;

        if (current->data < 0) {
            negTail->next = current;
            negTail = current;
        }
        else {
            nonNegTail->next = current;
            nonNegTail = current;
        }
        current = nextNode;
    }
    negTail->next = nonNegDummy.next;
    return negDummy.next;
}

int main() {
    int N;
    cin >> N;
    Node* head = buildList(N);
    Node* newHead = rearrangeList(head);

    Node* current = newHead;
    //输出
    while (current) {
        cout << current->data;
        current = current->next;
        if (current) cout << " ";
    }
    cout << endl;

    //进行删除操作
    while (newHead) {
        Node* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }
    return 0;
}