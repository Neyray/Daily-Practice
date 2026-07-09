#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构建哈希表加速查找
unordered_map<int, int> buildInMap(vector<int>& inorder) {
    unordered_map<int, int> in_map;
    for (int i = 0; i < inorder.size(); ++i) {
        in_map[inorder[i]] = i;
    }
    return in_map;
}

// 递归构建核心
TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder,
    int in_start, int in_end, int post_start, int post_end,
    unordered_map<int, int>& in_map) {

    if (in_start > in_end) return nullptr;

    // 后序末位为根节点
    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);

    // 哈希表直接获取分割点
    int split_idx = in_map[root_val];

    // 计算左右子树节点数
    int left_size = split_idx - in_start;

    // 递归构建子树（闭区间处理）
    root->left = buildHelper(inorder, postorder,
        in_start, split_idx - 1,
        post_start, post_start + left_size - 1,
        in_map);
    root->right = buildHelper(inorder, postorder,
        split_idx + 1, in_end,
        post_start + left_size, post_end - 1,
        in_map);
    return root;
}

// 主构建函数
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    auto in_map = buildInMap(inorder);
    return buildHelper(inorder, postorder,
        0, inorder.size() - 1,
        0, postorder.size() - 1,
        in_map);
}

// 前序遍历函数
void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // 测试用例
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Preorder result: ";
    preorderTraversal(root); // 预期输出：3 9 20 15 7

    return 0;
}