// K 个一组翻转链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;

    while (true) {
        // 1. 找到当前组的第 k 个节点
        ListNode* kth = groupPrev;

        for (int i = 1; i <= k; ++i) {
            kth = kth->next;
            if (kth == NULL) return dummy.next;
        }

        // 2. 保存下一组的头节点
        ListNode* groupNext = kth->next;

        // 3. 反转当前组
        ListNode* oldHead = groupPrev->next;
        ListNode* p = oldHead;
        ListNode* prev = groupNext;

        while (p != groupNext) {
            ListNode* temp = p->next;

            p->next = prev;

            prev = p;
            p = temp;
        }

        // 4. 连接反转后的链表
        groupPrev->next = prev;

        // 5. 更新下一组的前驱节点
        groupPrev = oldHead;
    }

    return dummy.next;
}