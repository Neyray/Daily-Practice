//BST转双向链表
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;   // 转换后当作 prev
    Node* right;  // 转换后当作 next

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

// 根据先序序列建树，-1 表示空节点
Node* buildTree() {
    int x;
    if (!(cin >> x)) {
        return NULL;
    }

    if (x == -1) {
        return NULL;
    }

    Node* root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

// head 指向双向链表头节点
// prev 指向中序遍历中当前节点的前一个节点
void inorderConvert(Node* root, Node*& head, Node*& prev) {
    if (root == NULL) {
        return;
    }

    // 1. 先处理左子树
    inorderConvert(root->left, head, prev);

    // 2. 处理当前节点 root
    if (prev == NULL) {
        // prev 为空，说明 root 是中序遍历第一个节点，也就是链表头
        head = root;
    }
    else {
        // 把上一个节点和当前节点连起来
        prev->right = root;
        root->left = prev;
    }

    // 当前节点处理完后，更新 prev
    prev = root;

    // 3. 再处理右子树
    inorderConvert(root->right, head, prev);
}

int main() {
    Node* root = buildTree();

    Node* head = NULL;
    Node* prev = NULL;

    inorderConvert(root, head, prev);

    // 遍历结束后，prev 就是尾节点
    Node* tail = prev;

    if (head != NULL && tail != NULL) {
        cout << head->val << " " << tail->val << endl;
    }

    return 0;
}