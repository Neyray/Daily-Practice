#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

Node* createList() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    string line;

    // 获取输入
    getline(cin, line);
    stringstream ss(line);

    while (ss >> val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

Node* mergeLists(Node* A, Node* B) {
    if (A == NULL) return B;
    Node* current = A;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = B;
    return A;
}

Node* mergeSortedLists(Node* A, Node* B) {
    Node dummy(0);
    Node* tail = &dummy;
    while (A != NULL && B != NULL) {
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

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = NULL;

    return mergeSortedLists(mergeSort(head), mergeSort(right));
}

void removeDuplicates(Node* head) {
    if (head == NULL) return;
    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }
}

void printLists(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteLists(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
}

int main() {
    cout << "请输入第一个链表的元素：";
    Node* A = createList();
    cout << "请输入第二个链表的元素：";
    Node* B = createList();

    Node* C = mergeLists(A, B);   // 合并链表
    C = mergeSort(C);              // 排序链表
    removeDuplicates(C);           // 去重操作
    printLists(C);                 // 输出链表
    deleteLists(C);                // 删除链表

    return 0;
}
