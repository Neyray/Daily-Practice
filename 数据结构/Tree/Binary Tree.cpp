#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;         
    TreeNode* left;  
    TreeNode* right; 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};


TreeNode * buildTreeHelper(vector<int>&preorder, int& preIdx, int inStart, int inEnd, unordered_map<int, int>&inMap) {
    // 递归终止条件：当前子树范围无效
    if (inStart > inEnd) return nullptr;

    // 从前序数组获取当前根节点值，并创建节点
    int rootVal = preorder[preIdx];
    TreeNode* root = new TreeNode(rootVal);

    // 查找当前根节点在中序数组中的位置，分割左右子树
    int inRootIdx = inMap[rootVal];

    // 前序索引递增，准备处理下一个根节点
    preIdx++;

    // 递归构建左子树（范围：inStart到inRootIdx-1）
    root->left = buildTreeHelper(preorder, preIdx, inStart, inRootIdx - 1, inMap);
    // 递归构建右子树（范围：inRootIdx+1到inEnd）
    root->right = buildTreeHelper(preorder, preIdx, inRootIdx + 1, inEnd, inMap);

    return root; // 返回当前构建的子树根节点
}


TreeNode * buildTree(vector<int>&preorder, vector<int>&inorder) {
    // 创建中序数组的值到索引的映射表（加速查找）
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i; 
    }

    int preIdx = 0; // 前序数组从第一个元素开始处理（根节点）
    // 调用辅助函数，初始范围是整个中序数组
    return buildTreeHelper(preorder, preIdx, 0, inorder.size() - 1, inMap);
}


void postorderTraversal(TreeNode * root, vector<int>&result) {
    if (!root) return; // 递归终止条件

    postorderTraversal(root->left, result);  // 先遍历左子树
    postorderTraversal(root->right, result); // 再遍历右子树
    result.push_back(root->val);             // 最后记录当前节点值
}

int main() {
    // 示例输入数据
    vector<int> preorder = { 3, 9, 20, 15, 7 };  // 前序：根 -> 左 -> 右
    vector<int> inorder = { 9, 3, 15, 20, 7 };   // 中序：左 -> 根 -> 右

    // 构建二叉树
    TreeNode* root = buildTree(preorder, inorder);

    // 执行后序遍历
    vector<int> postorder;
    postorderTraversal(root, postorder);

    // 输出后序结果（左 -> 右 -> 根）
    cout << "Postorder traversal: ";
    for (int num : postorder) {
        cout << num << " ";  // 预期输出：9 15 7 20 3 
    }

    return 0;
}