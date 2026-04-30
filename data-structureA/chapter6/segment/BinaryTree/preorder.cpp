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

void PreOrder11(BTNode* r){
    if(r!=NULL){
        cout<<r->data;
        PreOrder11(r->lchild);
        PreOrder11(r->rchild);
    }
}

//先序遍历的非递归算法1
void PreOrder2(BTNode* r){
    if(r==NULL)return;
    
    stack<BTNode*>st;
    BTNode* p;
    st.push(r);

    while(!st.empty()){
        p=st.top();st.pop();
        cout<<p->data;

        //先进栈右孩子
        if(p->rchild!=NULL)st.push(p->rchild);
        if(p->lchild!=NULL)st.push(p->lchild);
    }
}

//先序遍历的非递归算法2---一路向左
void PreOrder3(BTNode* r){
    if(r==NULL)return;
    
    stack<BTNode*>st;
    BTNode* p=r;

    while(!st.empty() || p!=NULL){
        //先遍历完全部的左子树
        while(p!=NULL){
            //由于是根左右，所以先输出
            cout<<p->data;
            st.push(p);//保存左子树的节点，用来找右子树节点
            p=p->lchild;
        }

        if(!st.empty()){
            p=st.top();st.pop();
            p=p->rchild;
        }
    }
}