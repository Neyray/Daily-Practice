// 将有序数组转化为平衡二叉树
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* sortedArrayToBST(vector<int>& nums){
    return build(nums,0,nums.size()-1);
}

TreeNode* build(vector<int>& nums,int left,int right){
    if(left>right)return NULL;

    int mid=left+(right-left)/2;
    TreeNode* root=new TreeNode(nums[mid]);

    root->left=build(nums,left,mid-1);
    root->right=build(nums,mid+1,right);
    return root; 
}