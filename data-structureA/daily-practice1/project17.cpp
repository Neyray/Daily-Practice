//对链表进行奇偶分离
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int d):data(d),next(NULL){}
};

Node* diverse(Node* head){
    if(head->next==NULL){return head;}
    if(head->next->next==NULL){return head;}

    Node* curr1=head->next;
    Node* curr2=head->next->next;Node* bhead=head->next->next;
    //先断开第一个的连接
    curr1->next=NULL;

    //一个是针对偶数个节点，另一个是针对奇数个节点

    //！！！
    //一定要把curr2!=NULL放在最前面，不然会出现NULL->next的情况
    //！！！
    while(curr2!=NULL && curr2->next!=NULL){
        Node* ans1=curr2->next;
        Node* ans2=curr2->next->next;

        curr1->next=ans1;//这个ans1是奇数位的最后一个节点
        curr2->next=ans2;//ans2是偶数位的最后一个节点

        curr1=ans1;
        curr2=ans2;
    }
    if(curr1!=NULL)curr1->next=NULL;//奇数链表完成
    if(curr2!=NULL)curr2->next=NULL;//偶数位

    curr1->next=bhead;

    return head;
}

int main(){
    string str;
    getline(cin,str);
    stringstream ss(str);
    string token;
    Node* head=new Node();
    Node* p=head;
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

    head=diverse(head);

    Node* curr=head->next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }


    return 0;
}