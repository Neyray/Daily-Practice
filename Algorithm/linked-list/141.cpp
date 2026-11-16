// 环形链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int v):val(v),next(NULL){}
};

bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;

    ListNode* p1 = head;
    ListNode* p2 = head;

    // 快指针一次走两步，必须保证两步可走
    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;

        if (p1 == p2)
            return true;
    }

    return false;
}