//输出二叉树的边界
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string val;
    Node* left;
    Node* right;

    Node(string v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* p) {
    return p != NULL && p->left == NULL && p->right == NULL;
}

// 在已有节点数组中查找节点
Node* findNode(vector<Node*>& nodes, string val) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->val == val) {
            return nodes[i];
        }
    }
    return NULL;
}

// 查找节点，如果不存在就新建
Node* getNode(vector<Node*>& nodes, string val) {
    Node* p = findNode(nodes, val);
    if (p != NULL) return p;

    p = new Node(val);
    nodes.push_back(p);
    return p;
}

Node* buildTree() {
    int N;
    cin >> N;

    vector<Node*> nodes;
    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        string fa, lch, rch;
        cin >> fa >> lch >> rch;

        Node* curr = getNode(nodes, fa);

        if (i == 0) {
            root = curr;
        }

        if (lch != "#") {
            curr->left = getNode(nodes, lch);
        }

        if (rch != "#") {
            curr->right = getNode(nodes, rch);
        }
    }

    return root;
}

// 判断某个节点是否已经加入答案，防止特殊情况下重复
bool existsInAns(vector<Node*>& ans, Node* p) {
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == p) return true;
    }
    return false;
}

// 加入左边界：从根开始，优先向左，没有左孩子就向右
// 注意：叶子不在这里加，因为叶子统一由 addLeaves 加
void addLeftBoundary(Node* root, vector<Node*>& ans) {
    Node* p = root;

    while (p != NULL) {
        if (!isLeaf(p)) {
            if (!existsInAns(ans, p)) {
                ans.push_back(p);
            }
        }

        if (p->left != NULL) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
}

// 加入所有叶子：从左到右
void addLeaves(Node* root, vector<Node*>& ans) {
    if (root == NULL) return;

    if (isLeaf(root)) {
        if (!existsInAns(ans, root)) {
            ans.push_back(root);
        }
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

// 加入右边界：从根的右侧开始，优先向右，没有右孩子就向左
// 先临时保存，再倒序加入答案
// 同样不加入叶子和根
void addRightBoundary(Node* root, vector<Node*>& ans) {
    vector<Node*> temp;

    Node* p;

    if (root->right != NULL) {
        p = root->right;
    } else {
        p = root->left;
    }

    while (p != NULL) {
        if (!isLeaf(p)) {
            temp.push_back(p);
        }

        if (p->right != NULL) {
            p = p->right;
        } else {
            p = p->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        if (!existsInAns(ans, temp[i])) {
            ans.push_back(temp[i]);
        }
    }
}

int main() {
    Node* root = buildTree();

    vector<Node*> ans;

    if (root != NULL) {
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i]->val;
    }

    return 0;
}