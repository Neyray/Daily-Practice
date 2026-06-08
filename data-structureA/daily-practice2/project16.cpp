//BST树的插入、删除、寻找
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insertVal(Node* root, int n) {
	if (root == NULL) return new Node(n);

	if (n < root->val) {
		root->left = insertVal(root->left, n);
	}
	else if (n > root->val) {
		root->right = insertVal(root->right, n);
	}

	return root;
}

// BST查找
bool find(Node* root, int x) {
	if (root == NULL) {
		return false;
	}

	if (x == root->val) {
		return true;
	}
	else if (x < root->val) {
		return find(root->left, x);
	}
	else {
		return find(root->right, x);
	}
}

// 只找最大节点，不输出
Node* getMax(Node* root) {
	Node* p = root;

	while (p->right != NULL) {
		p = p->right;
	}

	return p;
}

// 只找最小节点，不输出
Node* getMin(Node* root) {
	Node* p = root;

	while (p->left != NULL) {
		p = p->left;
	}

	return p;
}

// 输出最大值
void findMax(Node* root) {
	if (root == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	Node* p = getMax(root);
	cout << p->val << endl;
}

// 输出最小值
void findMin(Node* root) {
	if (root == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	Node* p = getMin(root);
	cout << p->val << endl;
}

Node* deleteVal(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	}

	if (x < root->val) {
		root->left = deleteVal(root->left, x);
	}
	else if (x > root->val) {
		root->right = deleteVal(root->right, x);
	}
	else {
		// 情况1：叶子节点
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// 情况2：只有右孩子
		else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}

		// 情况3：只有左孩子
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		// 情况4：左右孩子都有
		else {
			// 找左子树最大值，也就是中序前驱
			Node* maxVal = getMax(root->left);

			// 用前驱节点的值覆盖当前节点
			root->val = maxVal->val;

			// 再删除左子树中的那个前驱节点
			root->left = deleteVal(root->left, maxVal->val);
		}
	}

	return root;
}

int main() {
	int n;
	cin >> n;

	Node* root = NULL;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		if (str == "INSERT") {
			int x;
			cin >> x;
			root = insertVal(root, x);
		}
		else if (str == "FIND") {
			int x;
			cin >> x;

			if (find(root, x)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (str == "MAX") {
			findMax(root);
		}
		else if (str == "MIN") {
			findMin(root);
		}
		else if (str == "DELETE") {
			int x;
			cin >> x;

			if (!find(root, x)) {
				cout << "NOT FOUND" << endl;
			}
			else {
				root = deleteVal(root, x);
			}
		}
	}

	return 0;
}