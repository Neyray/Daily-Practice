//×î´ó¶þ²æÊ÷
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int max_idx = left;
    for (int i = left; i <= right; ++i) {
        if (nums[i] > nums[max_idx]) {
            max_idx = i;
        }
    }
    TreeNode* root = new TreeNode(nums[max_idx]);
    root->left = build(nums, left, max_idx - 1);
    root->right = build(nums, max_idx + 1, right);
    return root;
}

string serialize(TreeNode* root) {
    if (!root) return "";
    string left = serialize(root->left);
    string right = serialize(root->right);
    string res = to_string(root->val);
    if (left.empty() && right.empty()) {
        return res;
    }
    res += "(";
    res += left;
    if (!right.empty()) {
        res += "," + right;
    }
    res += ")";
    return res;
}

int main() {
    vector<int> nums;
    ifstream inFiles("in.txt");
    if (!inFiles) {
        cerr << "error!";
        return -1;
    }

    int num;
    while (inFiles >> num) {
        nums.push_back(num);
    }
    TreeNode* root = build(nums, 0, nums.size() - 1);
    cout << serialize(root) << endl;
    return 0;
}