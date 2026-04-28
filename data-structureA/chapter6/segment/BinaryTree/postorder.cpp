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

void PostOrder11(BTNode* r){
    if(r!=NULL){
        PostOrder11(r->lchild);
        PostOrder11(r->rchild);
        cout<<r->data;
    }
}

//非递归算法1
void PostOrder2(BTNode* r){
    if(r==NULL)return;

    BTNode* p;
    stack<BTNode*>st;
    vector<char>res;
    st.push(r);

    while(!st.empty()){
        p=st.top();st.pop();

        res.push_back(p->data);

        if(p->lchild!=NULL)st.push(p->lchild);
        if(p->rchild!=NULL)st.push(p->rchild);
    }

    vector<char>::reverse_iterator rit;
    for(rit=res.rbegin();rit!=res.rend();++rit){
        cout<<*rit;
    }
}

//非递归算法2
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

void PostOrder3(BTNode* r){
    if(r==NULL)return;

    stack<SNode>st;
    BTNode* p=r;
    Push(st,p);

    while(!st.empty()){
        SNode e=st.top();st.pop();

        p=e.p;
        if(e.flag)cout<<p->data;
        else{
            //先将根节点任务进栈
            st.push(SNode(p,true));
            if(p->rchild!=NULL)Push(st,p->rchild);
            if(p->lchild!=NULL)Push(st,p->lchild);
        }
    }
}