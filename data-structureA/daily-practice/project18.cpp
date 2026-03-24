//单链表逆置---迭代法
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int d):data(d),next(NULL){}
};

//这里的h是头节点之后的第一个元素
Node* reverse(Node* h){
    //只有一个元素或者为空链表
    if(h==NULL || h->next==NULL)return h;

    //使用快慢指针
    Node* slow=h;Node* fast=h->next;

    //这个slow是逆置后的最后一个元素，先将其指向NULL
    //必须放在fast定义的后面，不然fast就是NULL了1 2 3 4 5 -1
    slow->next=NULL;

    while(fast!=NULL){
        //暂存fast的下一个节点
        Node* ans1=fast->next;
        //进行逆置
        fast->next=slow;
        slow=fast;
        fast=ans1;
    }
    return slow;
}

int main(){
    Node* head=new Node();
    Node* p=head;

    string str;
    getline(cin,str);
    stringstream ss(str);
    string token;
    while(getline(ss,token,' ')){
        if(!token.empty() && token.back()=='\r'){
            token.pop_back();
        }
        if(token.empty())continue;
        if(token=="-1")break;

        Node* s=new Node(stoi(token));
        p->next=s;
        p=s;
    }
    p->next=NULL;

    head->next=reverse(head->next);

    Node* curr=head->next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    return 0;
}