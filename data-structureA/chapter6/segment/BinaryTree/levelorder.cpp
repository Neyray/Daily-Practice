#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 层次遍历（基础版：只输出序列）
void LevelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root); // 根节点入队

    while (!q.empty()) {
        Node* curr = q.front(); 
        q.pop(); // 取出队首节点

        cout << curr->val << " "; // 访问当前节点

        // 核心逻辑：左孩子先入队，右孩子后入队
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
}

// 层次遍历（进阶版：按层分组返回结果）
// 这在LeetCode（如题102）中非常常见，常用于需要知道“当前处于哪一层”的场景
vector<vector<int>> LevelOrderGrouped(Node* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // 当前队列的长度，就是这一层的节点数
        vector<int> currentLevel;

        // 专门用一个 for 循环把当前层的所有节点一次性处理完
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            currentLevel.push_back(curr->val);

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        res.push_back(currentLevel); // 将当前层的结果加入总结果
    }
    return res;
}