// 两数相加
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* p = &dummy;

    int carry = 0;


    // 要考虑链表长度不一致的情况
    while(l1 || l2 || carry) {
        int sum = carry;

        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        p->next = new ListNode(sum % 10);
        p = p->next;
    }

    return dummy.next;
}