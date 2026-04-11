//反转链表节点
//只有 cin >> 之后接 getline，才需要 cin.ignore()！！！
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int d):data(d),next(NULL){}
};

Node* createList(int arr[],int n){
    Node* head=new Node();
    Node* p=head;
    //采用尾插法建表
    for(int i=0;i<n;++i){
        Node* q=new Node(arr[i]);
        p->next=q;
        p=q;
    }
    p->next=NULL;

    return head;
}

Node* reverse(int left, int right, Node* head){
    if(head->next == NULL || head->next->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head;

    for(int i = 1; i <= left-1; ++i)
        slow = slow->next;
    for(int j = 1; j <= right; ++j)
        fast = fast->next;

    Node* temp = slow->next;   // 反转后的尾节点（原left）
    Node* curr2 = fast->next;  // right之后的节点

    // 三指针反转 [left, right]
    Node* prev = NULL;
    Node* cur = slow->next;
    while(cur != fast){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    // 处理fast（right节点）本身
    fast->next = prev;

    slow->next = fast;   // 前段接反转后的头
    temp->next = curr2;  // 反转后的尾接后段

    return head;
}

void printList(Node* head){
    if(head->next==NULL)return;

    Node* p=head->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    int arr[100];

    string str;
    getline(cin,str);

    stringstream ss(str);
    string token;
    int i=0;
    while(getline(ss,token,' ')){
        if(!token.empty() && token.back()=='\r'){
            token.pop_back();
        }
        if(token.empty())continue;

        int num=stoi(token);
        arr[i]=num;
        i++;//i即为数组的元素个数
    }

    int left,right;
    cin>>left>>right;

    Node* head=createList(arr,i);
    printList(head);
    head=reverse(left,right,head);
    printList(head);

    return 0;
}