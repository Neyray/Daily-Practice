//在BST中查找第一个大于k的节点值
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// 根据层序序列建树，-1 表示空结点
Node* buildTree(vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) {
        return NULL;
    }

    Node* root = new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nums.size()) {
        Node* cur = q.front();
        q.pop();

        if (i < nums.size() && nums[i] != -1) {
            cur->left = new Node(nums[i]);
            q.push(cur->left);
        }
        i++;

        if (i < nums.size() && nums[i] != -1) {
            cur->right = new Node(nums[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// 查找 BST 中大于 k 的最小值
int findFirstGreater(Node* root, int k) {
    int ans = -1;

    while (root != NULL) {
        if (root->data > k) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    while (line.size() == 0) {
        getline(cin, line);
    }

    stringstream ss(line);
    vector<int> nums;
    int x;

    while (ss >> x) {
        nums.push_back(x);
    }

    int k;
    cin >> k;

    Node* root = buildTree(nums);

    cout << findFirstGreater(root, k);

    return 0;
}