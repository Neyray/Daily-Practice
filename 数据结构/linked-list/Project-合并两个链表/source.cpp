#include <iostream>
#include <vector>
using namespace std;

// 链表节点结构
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// 数组转链表
Node* arrayToList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// 合并两个链表
Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    Node* curr = l1;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = l2;
    return l1;
}

// 归并排序（链表版）
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* curr = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        }
        else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    // 快慢指针找中点
    Node* slow = head, * fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 分割链表
    Node* right = slow->next;
    slow->next = nullptr;

    return mergeSortedLists(mergeSort(head), mergeSort(right));
}

// 去重操作
void removeDuplicates(Node* head) {
    if (!head) return;
    Node* curr = head;
    while (curr->next) {
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

// 打印链表
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 释放内存
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    vector<int> arr1 = { 3, 1, 4, 2, 2 };
    vector<int> arr2 = { 5, 7, 6, 4, 5 };

    // 创建链表
    Node* list1 = arrayToList(arr1);
    Node* list2 = arrayToList(arr2);

    // 合并链表
    Node* merged = mergeLists(list1, list2);

    // 排序 + 去重
    merged = mergeSort(merged);
    removeDuplicates(merged);

    // 输出结果
    cout << "去重后的有序链表：";
    printList(merged);

    // 释放内存
    deleteList(merged);

    return 0;
}
