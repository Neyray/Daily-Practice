// 删除链表的倒数第 N 个结点
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    // fast 先走 n 步
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // fast 到达最后一个节点
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // 删除 slow 后面的节点
    ListNode* temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return dummy.next;
}