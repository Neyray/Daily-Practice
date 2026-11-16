// 反转链表 II
// 使用dummy(0)：
// (1)删除节点，尤其是删除头节点。
// (2)插入节点，尤其是在头部插入。
// (3)反转链表，尤其是反转区间可能从第一个节点开始。
// (4)合并两个链表。
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next=head;

    ListNode* p1=&dummy;

    // 找到反转区间前一个节点
    for(int i=1;i<left;i++){
        p1=p1->next;
    }

    ListNode* prev=p1->next;
    ListNode* nhead=prev;
    ListNode* cur=prev->next;

    int count=0;

    while(count<right-left){
        ListNode* temp=cur->next;
        cur->next=prev;

        prev=cur;
        cur=temp;

        count++;
    }

    // 重新连接
    p1->next=prev;
    nhead->next=cur;

    return dummy.next;
}