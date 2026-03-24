//链表去重
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

Node* deleteElem(Node* head){
    if(head->next==NULL || head->next->next==NULL)return head;

    Node* p=head->next;

    while(p!=NULL && p->next!=NULL){
        Node* s=p->next;
        if(p->data==s->data){
            p->next=s->next;
            delete s;
        }
        else{
            p=s;
        }
    }
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

    head=deleteElem(head);

    Node* curr=head->next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    return 0;
}