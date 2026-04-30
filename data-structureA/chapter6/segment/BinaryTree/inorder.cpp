#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild;
    BTNode* rchild;

    BTNode() : lchild(NULL), rchild(NULL) {}
    BTNode(char ch) : data(ch), lchild(NULL), rchild(NULL) {}
};

void InOrder11(BTNode* r){
    if(r!=NULL){
        InOrder11(r->lchild);
        cout<<r->data;
        InOrder11(r->rchild);
    }
}


//非递归算法1
struct SNode{
    BTNode* p;
    bool flag;

    SNode(){}
    SNode(BTNode* p1,bool flag1){
        p=p1;
        flag=flag1;
    }
};

void Push(stack<SNode>& st,BTNode* p){
    //叶子节点为可直接执行任务
    if(p->lchild==NULL && p->rchild==NULL)st.push(SNode(p,true));
    else st.push(SNode(p,false));
}

void Inorder2(BTNode* r){
    if(r==NULL)return;

    stack<SNode>st;
    BTNode* p=r;
    Push(st,p);

    while(!st.empty()){
        SNode e=st.top();st.pop();
        p=e.p;

        //e可以直接执行
        if(e.flag)cout<<p->data;
        else{
            if(p->rchild!=NULL) Push(st,p->rchild);
            //访问根节点的任务进栈（还没有输出的！）
            //此时将flag设为true，是因为之后弹栈弹到这个元素时直接输出了
            st.push(SNode(p,true));
            if(p->lchild!=NULL)Push(st,p->lchild);
        }
    }
}


//非递归算法2---一路向左
void Inorder3(BTNode* r){
    if(r==NULL)return;

    stack<BTNode*>st;
    BTNode* p=r;

    while(!st.empty() || p!=NULL){
        //将所有左节点进栈
        while(p!=NULL){
            st.push(p);
            p=p->lchild;
        }

        if(!st.empty()){
            p=st.top();st.pop();
            cout<<p->data;
            p=p->rchild;
        }
    }
}