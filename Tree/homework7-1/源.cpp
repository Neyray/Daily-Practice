/*
【问题描述】写程序把一棵二叉树采用二叉链存储结构存储，并求该二叉树b的宽度（采用递归方法）

【输入形式】表示一棵二叉树的数组

【输出形式】该二叉树的宽度
【样例输入】root=[6,2,8,0,4,7,9,null,null,3,5]

【样例输出】4
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode {
    string x;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string x) : x(x), left(NULL), right(NULL) {}
};

//类似BFS，完全二叉树
TreeNode* buildTree(const vector<string>& input) {
    if (input.empty() || input[0] == "null") {
        return NULL;
    }

    TreeNode* root = new TreeNode(input[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    int n = input.size();

    while (i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (i < n && input[i] != "null") {
            current->left = new TreeNode(input[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && input[i] != "null") {
            current->right = new TreeNode(input[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void dfs(TreeNode* node, int level, unordered_map<int, int>& widthAtLevel, int& maxWidth) {
    if (!node) return;

    widthAtLevel[level]++;
    maxWidth = max(maxWidth, widthAtLevel[level]);

    dfs(node->left, level + 1, widthAtLevel, maxWidth);
    dfs(node->right, level + 1, widthAtLevel, maxWidth);
}

int calculateWidth(TreeNode* root) {
    if (!root) return 0;

    unordered_map<int, int> widthAtLevel;
    int maxWidth = 0;
    dfs(root, 0, widthAtLevel, maxWidth);

    return maxWidth;
}

// 去除字符串首尾的空格
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n");
    return s.substr(start, end - start + 1);
}

int main() {
    vector<string> input;
    string line;
    getline(cin, line);

    // 提取数组部分
    size_t bracketStart = line.find('[');
    size_t bracketEnd = line.find(']');
    if (bracketStart == string::npos || bracketEnd == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    string arrayStr = line.substr(bracketStart + 1, bracketEnd - bracketStart - 1);
    stringstream ss(arrayStr);
    string token;
    while (getline(ss, token, ',')) {
        token = trim(token);
        input.push_back(token);
    }

    TreeNode* root = buildTree(input);
    cout << calculateWidth(root) << endl;

    return 0;
}