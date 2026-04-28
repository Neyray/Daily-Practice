//3.递归删除链表节点
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x):val(x),next(NULL){}
};

ListNode* removeElements(ListNode* head,int x){
    if(head==NULL){
        return NULL;
    }

    head->next=removeElements(head->next,x);// 1. 先让后面的链表完成删除

    if(head->val==x){        // 2. 再看当前的 head 要不要删除
        ListNode* temp=head->next;
        delete head;
        head=temp;
    }

    return head;
}

int main(){
    int n;
    cin>>n;

    if(n<=0){
        cout<<"-1";
        return 0;
    }

    int num;
    cin>>num;
    ListNode* head=new ListNode(num);
    ListNode* current=head;

    for(int i=1;i<n;++i){
        cin>>num;
        current->next=new ListNode(num);
        current=current->next;
    }

    int x;
    cin>>x;

    head=removeElements(head,x);

    if(head==NULL){
        cout<<"-1";
    }else{
        current=head;
        while(current!=NULL){
            cout<<current->val;
            if(current->next!=NULL)cout<<" ";
            current=current->next;
        }
    }

    return 0;
}