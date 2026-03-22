//递增链表去重
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

int main() {
    Node* head = new Node();  // 哑节点
    Node* p = head;
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            p->next = new Node(stoi(token));
            p = p->next;
        }
    }

    // curr 是前驱，curr->next 是待检查节点
    Node* curr = head->next;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node* del = curr->next;
            curr->next = del->next;  // curr 仍是前驱，继续检查新的 curr->next，不能移动curr！！！
            delete del;
        } else {
            curr = curr->next;
        }
    }

    Node* q = head->next;
    bool first = true;
    while (q != nullptr) {
        if (!first) cout << " ";
        cout << q->data;
        first = false;
        q = q->next;
    }
    cout << endl;
    return 0;
}