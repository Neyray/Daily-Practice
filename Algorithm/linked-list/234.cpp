// 回文链表
// 使用快指针，判断条件：fast!=NULL && fast->next!=NULL
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(NULL){}
    ListNode(int v):val(v),next(NULL){}
};


bool isPalindrome(ListNode* head) {
    ListNode* fast=head;
    ListNode* slow=head;
    ListNode* prev=nullptr;

    // 寻找中点，同时反转前半部分
    while(fast && fast->next){
        fast=fast->next->next;

        ListNode* temp=slow->next;
        slow->next=prev;

        prev=slow;
        slow=temp;
    }

    // 奇数长度，跳过中间节点
    if(fast){
        slow=slow->next;
    }

    // 比较前后两部分
    while(prev && slow){
        if(prev->val != slow->val){
            return false;
        }

        prev=prev->next;
        slow=slow->next;
    }

    return true;
}