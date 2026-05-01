//以括号表示法输入该二叉树的所有结点，输出前序，中序，后序遍历
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct BTNode{
    char val;
    BTNode* left;
    BTNode* right;

    BTNode(char ch):val(ch),left(NULL),right(NULL){}
};

//构建二叉树
BTNode* buildTree(const string& str){
    int n=str.length();
    int i=0;
    int k=1;//用来判断是左子树还是右子树
    stack<BTNode*>st;
    BTNode* root=NULL;
    BTNode* p=NULL;

    while(i<n){
        if(str[i]=='('){
            //说明之前这个节点有子树,需要进栈暂存
            st.push(p);
            k=1;
            i++;
        }
        else if(str[i]==','){
            k=2;
            i++;
        }
        else if(str[i]==')'){
            if(!st.empty()){
                st.pop();
            }
            i++;
        }
        else{
            //由于是字母，所以只需要处理一位
            p=new BTNode(str[i]);
            if(root==NULL)root=p;
            else{
                if(!st.empty()){
                    if(k==1)st.top()->left=p;
                    else if(k==2)st.top()->right=p;
                }
            }
            i++;
        }
    }

    return root;
}

//前序遍历
void preorder(BTNode* root){
    if(root==NULL)return;

    //采用一路向下的方式
    BTNode* p=root;
    stack<BTNode*>st;

    while(!st.empty() || p!=NULL){
        while(p!=NULL){
            cout<<p->val;

            //不要忘记把输出过的节点存入栈中，用于后续找右子树
            st.push(p);
            p=p->left;
        }

        if(!st.empty()){
            p=st.top();st.pop();//回溯到上一个节点
            p=p->right;
        }
    }
}


//中序遍历
//采用标记的方式
struct Node{
    BTNode* p;
    bool flag;

    Node(BTNode* curr,bool fl):p(curr),flag(fl){}
};

void Push(stack<Node*>& st,BTNode* p){
    //可以直接输出
    if(p->left==NULL && p->right==NULL)st.push(new Node(p,true));
    else st.push(new Node(p,false));
}

void inorder(BTNode* root){
    if(root==NULL)return;

    stack<Node*>st;
    BTNode* p=root;
    Push(st,root);

    while(!st.empty()){
        Node* e=st.top();st.pop();
        BTNode* p=e->p;

        if(e->flag)cout<<p->val;
        else{
            if(p->right!=NULL)Push(st,p->right);
            st.push(new Node(p,true));
            if(p->left!=NULL)Push(st,p->left);
        }
    }
}

//后序遍历
void postorder(BTNode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val;
    }
}

int main(){
    string str;
    cin>>str;

    BTNode* root=buildTree(str);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}