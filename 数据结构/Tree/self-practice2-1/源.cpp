//由层次遍历和中序遍历结果得出前序遍历
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
};

//提取字符并存入数组
vector<string> split(const string& s) {
    vector<string> res;
    istringstream iss(s);
    string token;
    while (iss >> token) {
        res.push_back(token);
    }
    return res;
}

TreeNode* buildTree(vector<string> level, int in_start, int in_end, unordered_map<string, int>& in_map) {
    if (level.empty() || in_start > in_end) {
        return nullptr;
    }
    string root_val = level[0];
    TreeNode* root = new TreeNode(root_val);
    int index = in_map[root_val];

    //进行分区
    vector<string> left_level, right_level;
    for (int i = 1; i < level.size(); ++i) {
        string val = level[i];
        int pos = in_map[val];
        if (pos >= in_start && pos <= index - 1) {
            left_level.push_back(val);
        }
        else if (pos >= index + 1 && pos <= in_end) {
            right_level.push_back(val);
        }
    }

    root->left = buildTree(left_level, in_start, index - 1, in_map);
    root->right = buildTree(right_level, index + 1, in_end, in_map);
    return root;
}

void preorder(TreeNode* root, vector<string>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string level_line;
    getline(cin, level_line);
    vector<string> level = split(level_line);

    string in_line;
    getline(cin, in_line);
    vector<string> in_order = split(in_line);

    unordered_map<string, int> in_map;
    for (int i = 0; i < in_order.size(); ++i) {
        in_map[in_order[i]] = i;
    }

    TreeNode* root = buildTree(level, 0, n - 1, in_map);

    vector<string> pre_order;
    preorder(root, pre_order);

    for (int i = 0; i < pre_order.size(); ++i) {
        if (i > 0) cout << " ";
        cout << pre_order[i];
    }
    cout << endl;

    return 0;
}