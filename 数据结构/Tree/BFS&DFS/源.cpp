#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
BFS使用队列，按层级顺序访问节点

DFS使用栈（递归隐式使用系统栈），优先访问到最深节点

BFS空间复杂度最差为O(n)，DFS最差空间复杂度为O(h)（h为树的高度）
*/

// BFS实现（层序遍历），广度优先
void BFS(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";  // 访问当前节点

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// DFS递归实现，深度优先
void DFS_preorder(TreeNode* node) {   // 前序遍历
    if (!node) return;
    cout << node->val << " ";  // 访问当前节点
    DFS_preorder(node->left);
    DFS_preorder(node->right);
}

void DFS_inorder(TreeNode* node) {    // 中序遍历
    if (!node) return;
    DFS_inorder(node->left);
    cout << node->val << " ";  // 访问当前节点
    DFS_inorder(node->right);
}

void DFS_postorder(TreeNode* node) {  // 后序遍历
    if (!node) return;
    DFS_postorder(node->left);
    DFS_postorder(node->right);
    cout << node->val << " ";  // 访问当前节点
}

int main() {
    /* 创建示例树：
          1
        /   \
       2     3
      / \
     4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "BFS结果：";
    BFS(root);  // 输出：1 2 3 4 5

    cout << "\nDFS前序：";
    DFS_preorder(root);  // 输出：1 2 4 5 3

    cout << "\nDFS中序：";
    DFS_inorder(root);   // 输出：4 2 5 1 3

    cout << "\nDFS后序：";
    DFS_postorder(root); // 输出：4 5 2 3 1

    return 0;
}