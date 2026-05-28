//判断是否是平衡二叉树
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

struct Node {
	int num;
	Node* left;
	Node* right;

	Node(int n) {
		num = n;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree(vector<string>arr, int i) {
	if (i >= arr.size())return NULL;

	if (arr[i] == "null")return NULL;

	Node* root = new Node(stoi(arr[i]));
	root->left = buildTree(arr, 2 * i + 1);
	root->right = buildTree(arr, 2 * i + 2);

	return root;
}


int checkHeight(Node* root) {
	if (root == NULL)return 0;

	int leftHeight = checkHeight(root->left);
	if (leftHeight == -1)return -1;

	int rightHeight = checkHeight(root->right);
	if (rightHeight == -1)return -1;

	if (abs(leftHeight - rightHeight) > 1)return -1;

	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
	if (checkHeight(root) == -1)return false;
	else return true;
}

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");

	vector<string>arr;
	string str;
	while (in >> str) {
		arr.push_back(str);
	}

	Node* root = buildTree(arr, 0);
	if (isBalanced(root))out << "True";
	else out << "False";

	return 0;
}