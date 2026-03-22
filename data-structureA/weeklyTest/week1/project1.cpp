//求链表A-B的内容
/*
在遍历一个链表时，只需要用一个while循环（用多了容易搞混），如果是需要前驱，判断条件就是p->next!=NULL;如果是当前节点，就是p!=NULL；循环内部使
用if(条件成立）//进行删除操作，而不是if(条件不成立，指针向后移）。
else则用来移动指针，每次移动一位，这样对于当前节点，由于判断条件p!=NULL，那
么最多到最后一个元素，p->data是成立的；对于前驱节点，最多到倒数第二个节点，执行p->next->data也不会失败，所以解决了判断条件混乱的情况
*/

//前驱模式里，删除和移动是互斥的——删除之后不移动，不删除才移动。
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d = 0) : data(d), next(nullptr) {}
};

// 用哑节点建链表，返回哑节点
Node* buildList(int n) {
    Node* head = new Node();  // 哑节点
    Node* p = head;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        p->next = new Node(num);
        p = p->next;
    }
    return head;
}

// 从 A 中删去所有在 B 中出现的元素，直接在 ahead 上操作
Node* subtract(Node* ahead, Node* bhead) {
    Node* b = bhead->next;
    while (b != nullptr) {
        // a 是前驱指针，a->next 才是被检查/删除的节点
        Node* a = ahead;                            // 从哑节点开始
        while (a->next != nullptr) {
            if (a->next->data == b->data) {
                Node* del = a->next;
                a->next = del->next;                // 跳过
                delete del;
                // 不移动 a，因为新的 a->next 还要检查
            } else {
                a = a->next;
            }
        }
        b = b->next;
    }
    return ahead;
}

int main() {
    int m, n; cin >> m >> n;
    Node* ahead = buildList(m);
    Node* bhead = buildList(n);
    Node* result = subtract(ahead, bhead);
    
    Node* p = result->next;
    bool first = true;
    while (p != nullptr) {
        if (!first) cout << " ";
        cout << p->data;
        first = false;
        p = p->next;
    }
    cout << endl;
    return 0;
}