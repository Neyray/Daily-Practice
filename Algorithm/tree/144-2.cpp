// 二叉树的前序遍历
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

//！！！
//这个算法只能先输出根
//先序遍历的非递归算法1
void PreOrder2(TreeNode* r){
    if(r==NULL)return;

    stack<TreeNode*>st;
    st.push(r);

    while(!st.empty()){
        TreeNode* p=st.top();st.pop();
        cout<<p->val;

        //先进栈右孩子
        if(p->right!=NULL)st.push(p->right);
        if(p->left!=NULL)st.push(p->left);
    }
}