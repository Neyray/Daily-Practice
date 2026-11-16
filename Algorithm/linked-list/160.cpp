// 相交链表
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};

// 两个指针分别走完对方的链表，消除长度差异
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        pA = (pA == nullptr) ? headB : pA->next;
        pB = (pB == nullptr) ? headA : pB->next;
    }

    return pA;
}