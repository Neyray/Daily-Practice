// 环形链表II
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int v):val(v),next(NULL){}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // 第一阶段：快慢指针判断是否存在环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // 第二阶段：一个指针从头节点出发
            // 另一个指针从相遇点出发
            // 两者每次走一步，最终在环入口相遇
            ListNode* p = head;

            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }

            return p;
        }
    }

    return NULL;
}