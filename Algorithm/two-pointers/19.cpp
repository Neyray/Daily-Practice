// 删除链表的倒数第 N 个结点
#include <iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;

    ListNode(int v):val(v),next(NULL){}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next=head;

    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // 快指针先走 n+1 步
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    // 快慢指针同步移动
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 此时 slow 指向待删除节点的前驱节点
    slow->next = slow->next->next;

    return dummy.next;
}