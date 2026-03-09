#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 释放链表内存
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

// 检查值是否在链表中存在
bool isExist(ListNode* head, int val) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// 合并两个链表并去重
ListNode* mergeAndRemoveDuplicates(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // 遍历第一个链表
    while (l1 != nullptr) {
        if (!isExist(dummy->next, l1->val)) {
            //相当于重新创建了一个节点连在新的链表上
            current->next = new ListNode(l1->val);
            current = current->next;
        }
        l1 = l1->next;
    }

    // 遍历第二个链表
    while (l2 != nullptr) {
        if (!isExist(dummy->next, l2->val)) {
            current->next = new ListNode(l2->val);
            current = current->next;
        }
        l2 = l2->next;
    }

    ListNode* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main() {
    // 创建第一个链表
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    // 创建第二个链表
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // 打印原始链表
    std::cout << "List 1: ";
    printList(l1);
    std::cout << "List 2: ";
    printList(l2);

    // 合并链表并去重
    ListNode* mergedList = mergeAndRemoveDuplicates(l1, l2);

    // 打印合并后的链表
    std::cout << "Merged list: ";
    printList(mergedList);

    // 释放内存
    deleteList(l1);
    deleteList(l2);
    deleteList(mergedList);

    return 0;
}
