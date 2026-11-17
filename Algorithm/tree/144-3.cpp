// 二叉树的前序遍历
#include <iostream>
#include <stack>
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
//只有一路向左才不需要在循环外压栈，因为它是先遍历完所有，再回溯
//先序遍历的非递归算法2---一路向左
void PreOrder3(TreeNode* r) {
    if (r == nullptr) return;

    stack<TreeNode*> st;
    TreeNode* p = r;

    while (!st.empty() || p != nullptr) {
        //先遍历完全部的左子树
        while (p != nullptr) {
            //由于是根左右，所以先输出
            cout << p->val;
            st.push(p);//保存左子树的节点，用来找右子树节点
            p = p->left;
        }

        if (!st.empty()) {
            p = st.top(); st.pop();
            //转到右子树，之前向下遍历已经输出“根左”了
            p = p->right;
        }
    }
}