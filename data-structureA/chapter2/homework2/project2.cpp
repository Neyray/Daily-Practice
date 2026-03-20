//将链表后面的元素一个一个插入链表中
//输入形式是：Address,Data,next
//第一行是第一个节点的地址+接下来输入的数据个数
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Node{
    string addr;
    int data;
    string nextAddr;
    Node* next;
    Node* prior;

    Node(){
        addr="";
        data=0;
        nextAddr="";
        next=NULL;
        prior=NULL;
    }

    Node(string ad,int d,string nad):addr(ad),data(d),nextAddr(nad),next(NULL),prior(NULL){}
};

class LinkList{
public:
    Node* head;
    Node* tail;

    LinkList(){
        head=new Node();
        tail=new Node();
    }

    ~LinkList(){
        Node* p=head;
        while(p!=NULL){
            Node* q=p->next;
            delete p;
            p=q;
        }
    }

    //根据输入来创建链表
    Node* createList(vector<Node>data){
        int n=data.size();
        sort(data.begin(),data.end(),[](Node a,Node b){return a.data<b.data;});

        Node* p=head;
        for(int i=0;i<n;++i){
            Node* s=new Node(data[i].addr,data[i].data,data[i].nextAddr);
            p->next=s;
            s->prior=p;
            p=s;
        }
        //这个等号两边有点不确定
        p->next=tail;
        tail->prior=p;
        return head;
    }


    //对链表进行操作
    Node* reverse(int n){
        //新建一个列表的头节点
        Node* newHead=new Node();
        Node* curr=newHead;
        Node* p=head->next;
        Node* q=tail->prior;
        while(p->data > q->data){
            //新建节点来存储后继或前驱节点
            Node* newp=p->next;
            Node* newq=q->prior;

            curr->next=q;
            q->prior=NULL;

            curr=q;
            curr->next=p;
            curr=p;

            p=newp;q=newq;
        }
    }
    
};
