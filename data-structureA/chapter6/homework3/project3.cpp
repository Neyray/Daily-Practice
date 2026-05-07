//求二叉树距离为k的节点
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// 去掉字符串首尾空格
string trim(string s) {
    while (!s.empty() && s[0] == ' ') {
        s.erase(s.begin());
    }

    while (!s.empty() && s[s.length() - 1] == ' ') {
        s.erase(s.end() - 1);
    }

    return s;
}

// 把 "[1,2,3,#,#]" 切分成 {"1","2","3","#","#"}
vector<string> splitTreeString(string s) {
    vector<string> res;

    if (!s.empty() && s[0] == '[') {
        s.erase(s.begin());
    }

    if (!s.empty() && s[s.length() - 1] == ']') {
        s.erase(s.end() - 1);
    }

    string token;
    stringstream ss(s);

    while (getline(ss, token, ',')) {
        token = trim(token);
        res.push_back(token);
    }

    return res;
}

// 根据层序序列建树
TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "#") {
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(nodes[0]));

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "#") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "#") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// 根据值找到 target 节点
TreeNode* findTarget(TreeNode* root, int targetVal) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == targetVal) {
        return root;
    }

    TreeNode* leftResult = findTarget(root->left, targetVal);
    if (leftResult != NULL) {
        return leftResult;
    }

    return findTarget(root->right, targetVal);
}

// 找 root 到 target 的路径
bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    if (root == NULL) {
        return false;
    }

    path.push_back(root);

    if (root == target) {
        return true;
    }

    if (findPath(root->left, target, path)) {
        return true;
    }

    if (findPath(root->right, target, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

// 从某个节点开始，向下找距离为 depth 的所有节点
void collectDown(TreeNode* root, int depth, vector<int>& ans) {
    if (root == NULL) {
        return;
    }

    if (depth == 0) {
        ans.push_back(root->val);
        return;
    }

    collectDown(root->left, depth - 1, ans);
    collectDown(root->right, depth - 1, ans);
}

// 求距离 target 为 k 的所有节点
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    vector<TreeNode*> path;

    findPath(root, target, path);

    // 1. 优先输出 target 的子孙节点
    collectDown(target, k, ans);

    int n = path.size();

    // 从 target 的父节点开始，逐层往上处理
    for (int i = n - 2; i >= 0; i--) {
        TreeNode* ancestor = path[i];
        TreeNode* child = path[i + 1];

        int distToAncestor = n - 1 - i;

        // 当前祖先本身距离 target 为 k
        if (distToAncestor == k) {
            ans.push_back(ancestor->val);
        }

        // 去当前祖先的另一棵子树里找
        else if (distToAncestor < k) {
            TreeNode* brotherSubtree = NULL;

            if (ancestor->left == child) {
                brotherSubtree = ancestor->right;
            } else {
                brotherSubtree = ancestor->left;
            }

            int rest = k - distToAncestor - 1;

            collectDown(brotherSubtree, rest, ans);
        }
    }

    return ans;
}

// 释放二叉树
void destroyTree(TreeNode* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int main() {
    string treeStr;
    int targetVal;
    int k;

    ifstream inFile("in.txt");

    getline(inFile, treeStr);
    inFile >> targetVal;
    inFile >> k;

    vector<string> nodes = splitTreeString(treeStr);

    TreeNode* root = buildTree(nodes);
    TreeNode* target = findTarget(root, targetVal);

    vector<int> ans = distanceK(root, target, k);

    cout << "[";

    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << ",";
        }
        cout << ans[i];
    }

    cout << "]";

    destroyTree(root);

    return 0;
}