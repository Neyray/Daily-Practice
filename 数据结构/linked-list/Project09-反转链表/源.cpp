#include <iostream>

// 定义链表节点的结构体
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int x) : value(x), next(nullptr) {}
};

// 反转链表的函数
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextTemp = curr->next; // 暂存下一个节点

        curr->next = prev; // 当前节点的next指向前一个节点
        prev = curr; // 前一个节点更新为当前节点
        curr = nextTemp; // 当前节点更新为下一个暂存的节点
    }

    return prev; // 返回反转后的链表头节点
}

// 打印链表的函数（用于测试）
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // 创建一个链表 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    // 反转链表
    ListNode* reversedHead = reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    // 释放链表节点内存（避免内存泄漏）
    ListNode* current = reversedHead;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
