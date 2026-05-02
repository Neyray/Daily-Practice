//合并两个有序链表
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

Node* merge(Node* ahead,Node* bhead){
    Node* p=ahead->next;
    Node* q=bhead->next;
    Node* newHead=new Node();Node* curr=newHead;

    while(p!=NULL && q!=NULL){
        if(p->data<=q->data){
            Node* s=new Node(p->data);
            curr->next=s;
            curr=s;

            p=p->next;
        }
        else{
            Node* s=new Node(q->data);
            curr->next=s;
            curr=s;

            q=q->next;
        }
    }
    while(p!=NULL){
        Node* s=new Node(p->data);
        curr->next=s;
        curr=s;

        p=p->next;
    }
    while(q!=NULL){
        Node* s=new Node(q->data);
        curr->next=s;
        curr=s;

        q=q->next;
    }
    return newHead;
}

int main(){
    string str;
    int n=2;
    Node* ahead=new Node();Node* p=ahead;
    Node* bhead=new Node();Node* q=bhead;

    while(n>0){
        getline(cin,str);
        stringstream ss(str);
        string token;
        while(getline(ss,token,' ')){
            if(!token.empty() && token.back()=='\r'){
                token.pop_back();
            }
            if(token.empty())continue;
            if(token=="-1")continue;

            Node* s=new Node(stoi(token));
            if(n==2){
                p->next=s;
                p=s;
            }
            else if(n==1){
                q->next=s;
                q=s;
            }
        }
        n--;
    }
    p->next=NULL;
    q->next=NULL;

    Node* newHead=merge(ahead,bhead);

    Node* curr=newHead->next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    return 0;
}