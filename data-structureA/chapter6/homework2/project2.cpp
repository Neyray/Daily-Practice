//由二叉树的先序序列和中序序列构造二叉树并求其后序序列
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

struct BTNode{
    int val;
    BTNode* left;
    BTNode* right;

    BTNode(int v):val(v),left(NULL),right(NULL){}
};

BTNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd){
    if(preStart>preEnd || inStart>inEnd)return NULL;

    //先序遍历的第一个节点就是根节点
    BTNode* root=new BTNode(preorder[preStart]);
    int target=root->val;

    //找到中序遍历的根节点位置来划分左右子树
    int index=0;
    for(index=inStart;index<=inEnd;++index){
        if(inorder[index]==target)break;
    }

    //此时的index指向中序遍历的根节点
    //可以得到左子树个数
    int leftSize=index-inStart;

    //进行递归
    root->left=helper(preorder,preStart+1,preStart+leftSize,inorder,inStart,index-1);
    root->right=helper(preorder,preStart+leftSize+1,preEnd,inorder,index+1,inEnd);

    return root;
}

BTNode* buildTree(vector<int>& preorder,vector<int>& inorder){
    return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}


//后序遍历
void postorder(BTNode* root){
    if(root==NULL)return;

    stack<BTNode*>st;
    st.push(root);

    vector<int>res;

    while(!st.empty()){
        BTNode* p=st.top();st.pop();

        res.push_back(p->val);
        if(p->left!=NULL)st.push(p->left);
        if(p->right!=NULL)st.push(p->right);
    }

    for(int i=res.size()-1;i>=0;--i){
        cout<<res[i]<<" ";
    }
}

int main(){
    ifstream inFile("in.txt");

    int n;
    inFile>>n;

    vector<int>preorder,inorder;

    for(int i=0;i<n;++i){
        int num;
        inFile>>num;

        preorder.push_back(num);
    }

    for(int i=0;i<n;++i){
        int num;
        inFile>>num;

        inorder.push_back(num);
    }

    BTNode* root=buildTree(preorder,inorder);

    postorder(root);

    return 0;
}