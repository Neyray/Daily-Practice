// 环形链表 II
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int v):val(v),next(NULL){}
};

ListNode* detectCycle(ListNode* head) {
    if(head==NULL || head->next==NULL) return NULL;

    unordered_set<ListNode*> st;
    ListNode* p=head;

    while(p!=NULL){
        // 判断当前节点的地址是否已经出现过
        if(st.find(p) != st.end()) return p;

        // 存储节点地址，而不是节点值
        st.insert(p);
        p=p->next;
    }

    return NULL;
}