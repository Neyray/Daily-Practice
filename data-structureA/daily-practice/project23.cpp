//用递归法实现单链表逆置

/*
Node* newHead=reverse(curr->next);
这一步是递归到最后一个元素，

即if(curr->next==NULL)return curr;
的情况；此时newHead已经是最后一个元素了；

之后进行指针逆置；
curr->next->next=curr;
curr->next=NULL;
这个curr是从后往前的，但是是从倒数第二个开始的

最后返回新的第一个元素，还需要连到原来的头节点上
return newHead;
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
};

Node* reverse(Node* curr){
    //这里的curr是head的下一个节点，贸然访问下一个元素会导致错误！！！
    if(curr==NULL || curr->next==NULL)return curr;

    Node* newHead=reverse(curr->next);

    curr->next->next=curr;
    curr->next=NULL;

    return newHead;
}

int main(){
    string str;
    getline(cin,str);

    Node* head=new Node();
    Node* p=head;

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

    Node* q=head->next;
    while(q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }

    return 0;
}