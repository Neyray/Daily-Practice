// 反转链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* next = cur->next; // 1. 保存后继节点

        cur->next = pre;            // 2. 反转当前节点指针

        pre = cur;                  // 3. pre 前进
        cur = next;                 // 4. cur 前进
    }

    return pre;
}