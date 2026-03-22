#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct LinkNode{
    T data;
    LinkNode<T>* next;

    LinkNode():data(0),next(NULL){}
    LinkNode(T d):data(d),next(NULL){}
};

template <typename T>
class LinkList{
public:
    LinkNode<T>* head;
    
    //构造函数
    LinkList(){
        head=new LinkNode();
    }

    // 析构函数：释放所有结点内存
    ~LinkList(){
        LinkNode<T>* p=head;
        //需要加上一个指针q来存储p的后继节点
        LinkNode<T>* q;
        while(p!=NULL){
            q=p->next;
            delete p;
            p=q;
        }
    }

    //头插法建表
    void CreateF(T a[],int n){
        for(int i=0;i<n;++i){
            LinkNode<T>* s=new LinkNode(a[i]);
            s->next=head->next;
            head->next=s;
        }
    }

    //尾插法建表
    void createR(T a[],int n){
        LinkNode<T>* p=head;
        for(int i=0;i<n;++i){
            LinkNode<T>* s=new LinkNode(arr[i]);
            p->next=s;
            p=s;
        }
        p->next=NULL;
    }
    
    // 将元素 e 添加到链表末尾
    void add(T e){
        LinkNode<T>* p=head;
        while(p->next != NULL){
            p=p->next;
        }
        //此时p到了链表的最后一个节点
        //新建一个节点，存储数据e
        LinkNode<T>* curr=new LinkNode(e);
        p->next=curr;
    }

    // 在位置 i (下标) 插入元素 e
    bool Insert(T e,int i){
        if(i<0)return false;

        int cnt=-1;
        LinkNode<T>* p=head;
        while(p!=NULL && cnt < i-1){
            p=p->next;
            cnt++;
        }
        if(p==NULL)return false;

        LinkNode<T>* s=new LinkNode(e);
        s->next=p->next;
        p->next=s;
        return true;
    }

    // 删除位置 i (下标) 的元素
    bool deleteElem(int i){
        if(i<0)return false;
        LinkNode<T>* p=head;
        int cnt=-1;
        while(p!=NULL && cnt<i-1){
            p=p->next;
            cnt++;
        }
        if (p == NULL || p->next == NULL) return false;

        LinkNode<T>* q=p->next;
        p->next=q->next;
        delete q;
        return true;
    }

    // 遍历输出链表
    void display(){
        LinkNode<T>* p=head->next;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }

    // 获取链表长度
    int getLength(){
        int cnt=0;
        LinkNode<T>* p=head->next;
        //不是p->next！
        while(p!=NULL){
            //把cnt放在移动指针的前面，因为数的是当前元素
            cnt++;
            p=p->next;
        }
    }
};

#endif