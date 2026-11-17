// 二叉树的右视图
#include <iostream>
#include <vector>
#include <queue>
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

vector<int> rightSideView(TreeNode* root) {
    // 层次遍历
    if(root==NULL)return {};

    vector<int> ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int levelSize=q.size();

        // 找每一层最右边的元素
        for(int i=0;i<levelSize;++i){
            TreeNode* cur=q.front();q.pop();

            if(i==levelSize-1)ans.push_back(cur->val);

            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
        }
    }

    return ans;
}