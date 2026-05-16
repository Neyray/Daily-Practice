//计算一棵给定二叉树中的所有单分支结点个数
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;

	Node(char c) :val(c), left(NULL), right(NULL) {}
};

Node* createTree(string str, int i) {
	if (i >= str.size()) return NULL;

	if (str[i] == '#') return NULL;

	Node* root = new Node(str[i]);

	root->left = createTree(str, 2 * i + 1);
	root->right = createTree(str, 2 * i + 2);

	return root;
}

void findSingle(Node* root,int& count) {
	if (root == NULL)return;

	if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))count++;

	findSingle(root->left, count);
	findSingle(root->right, count);
}


int main() {
	string str;
	cin >> str;

	int idx = 0;
	Node* root = createTree(str, idx);

	int count = 0;
	findSingle(root, count);

	cout << count;

	return 0;
}