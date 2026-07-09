#include <iostream>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList() {
    int value;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> value) {
        ListNode* newNode = new ListNode(value);
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

ListNode* mergeSortedLinkedLists(ListNode* A, ListNode* B) {
    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while (A && B) {
        if (A->val < B->val) {
            tail->next = A;
            A = A->next;
        }
        else if (A->val > B->val) {
            tail->next = B;
            B = B->next;
        }
        else {
            tail->next = A;
            A = A->next;
            B = B->next;
        }
        tail = tail->next;
    }
    tail->next = (A != NULL) ? A : B;
    return dummy.next;
}

void printLinkedList(ListNode* head) {
    if (!head) return;
    cout << head->val;
    head = head->next;
    while (head) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

void freeLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* A = createLinkedList();
    ListNode* B = createLinkedList();
    ListNode* C = mergeSortedLinkedLists(A, B);
    printLinkedList(C);
    freeLinkedList(C);
    return 0;
}