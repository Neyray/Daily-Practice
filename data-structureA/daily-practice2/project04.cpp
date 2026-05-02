//二叉树的序列化和反序列化
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v) :val(v), left(NULL), right(NULL) {}
};

Node* buildTree(vector<int>& preorder, int& idx) {
	if (idx >= preorder.size())return NULL;
	if (preorder[idx] == -1) {
		idx++;
		return NULL;
	}

	Node* root = new Node(preorder[idx]);
	idx++;

	root->left = buildTree(preorder, idx);
	root->right = buildTree(preorder, idx);

	return root;
}

void preorder(Node* root,vector<string>& ans) {
	if (root == NULL) {
		ans.push_back("#");
		return;
	}

	ans.push_back(to_string(root->val));
	preorder(root->left,ans);
	preorder(root->right,ans);
}

void inorder(Node* root) {
	if (root == NULL)return;

	inorder(root->left);
	cout << root->val << ' ';
	inorder(root->right);
}

int main() {
	string str;
	getline(cin, str);
	stringstream ss(str);

	vector<int>node;
	string num;
	while (getline(ss, num, ' ')) {
		if (!num.empty() && num.back() == '\r') {
			num.pop_back();
		}
		if (num.empty())continue;

		node.push_back(stoi(num));
	}
	int idx = 0;
	Node* root = buildTree(node, idx);

	vector<string> ans;
	preorder(root,ans);
	int n = ans.size();
	for (int i = 0; i < n; ++i) {
		if (i == 0)cout << ans[i];
		else cout << "," << ans[i];
	}

	cout << endl;
	inorder(root);

	return 0;
}