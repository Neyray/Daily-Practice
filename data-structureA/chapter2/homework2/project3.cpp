#include <iostream>
#include <string>
using namespace std;

struct Node {
    char ch;
    Node* next;
    Node() : ch(' '), next(NULL) {}
    Node(char c) : ch(c), next(NULL) {}
};

class LinkList {
public:
    Node* head;
    LinkList() : head(NULL) {}

    ~LinkList() {
        if (!head) return;

        // 循环链表需要特殊处理，找到尾节点先断开
        //这里特别容易错！！！
        Node* p = head;
        while (p->next != head) p = p->next;
        p->next = NULL; // 断开循环

        p = head;
        while (p != NULL) {
            Node* q = p->next;
            delete p;
            p = q;
        }
    }

    Node* createList(string str) {
        int n = str.length();
        head = new Node(str[0]);
        Node* p = head;
        for (int i = 1; i < n; ++i) {
            Node* s = new Node(str[i]);
            p->next = s;
            p = s;
        }
        p->next = head;
        return head; // 补上返回值
    }
};

bool isSame(Node* ahead, Node* bhead, int n) {
    Node* p = ahead;
    Node* q = bhead;
    int cnt = 0;
    // 找到 b 链表中与 a 头节点相同字符的起始位置
    while (q->ch != p->ch && cnt < n) {
        q = q->next;
        cnt++;
    }
    if (cnt == n) return false;
    cnt = 0;
    while (cnt < n) {
        if (p->ch != q->ch) return false;
        p = p->next;
        q = q->next;
        cnt++;
    }
    return true;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() != str2.size()) {
        cout << "0";
        return -1;
    }
    int n = str1.size();
    LinkList l1, l2;
    Node* head1 = l1.createList(str1);
    Node* head2 = l2.createList(str2);
    cout << (isSame(head1, head2, n) ? "1" : "0");
    return 0;
}