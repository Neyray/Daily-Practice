//层次遍历序列和中序遍历序列构造对应的二叉树
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;

    Node(char c) : val(c), left(NULL), right(NULL) {}
};

Node* buildTree(vector<char> level, vector<char> in) {
    if (level.empty() || in.empty()) {
        return NULL;
    }

    // 1. 层次遍历的第一个结点一定是根
    char rootVal = level[0];
    Node* root = new Node(rootVal);

    // 2. 在中序遍历中找到根的位置
    int rootIndex = -1;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }

    // 3. 划分左、右子树的中序序列
    vector<char> leftIn, rightIn;

    for (int i = 0; i < rootIndex; i++) {
        leftIn.push_back(in[i]);
    }

    for (int i = rootIndex + 1; i < in.size(); i++) {
        rightIn.push_back(in[i]);
    }

    // 4. 为了判断某个结点属于左子树还是右子树，建立集合
    set<char> leftSet;
    set<char> rightSet;

    for (int i = 0; i < leftIn.size(); i++) {
        leftSet.insert(leftIn[i]);
    }

    for (int i = 0; i < rightIn.size(); i++) {
        rightSet.insert(rightIn[i]);
    }

    // 5. 根据中序划分结果，从层次序列中筛出左、右子树的层次序列
    vector<char> leftLevel, rightLevel;

    for (int i = 1; i < level.size(); i++) {
        if (leftSet.find(level[i]) != leftSet.end()) {
            leftLevel.push_back(level[i]);
        }
        else if (rightSet.find(level[i]) != rightSet.end()) {
            rightLevel.push_back(level[i]);
        }
    }

    // 6. 递归构造左右子树
    root->left = buildTree(leftLevel, leftIn);
    root->right = buildTree(rightLevel, rightIn);

    return root;
}

void preorder(Node* root, bool& first) {
    if (root == NULL) {
        return;
    }

    //处理输出
    if (!first) {
        cout << " ";
    }
    cout << root->val;
    first = false;

    preorder(root->left, first);
    preorder(root->right, first);
}

int main() {
    int n;
    bool firstCase = true;

    while (cin >> n) {
        vector<char> level(n);
        vector<char> in(n);

        for (int i = 0; i < n; i++) {
            cin >> level[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }

        Node* root = buildTree(level, in);

        if (!firstCase) {
            cout << endl << endl;
        }

        bool first = true;
        preorder(root, first);
        cout << endl;

        firstCase = false;
    }

    return 0;
}