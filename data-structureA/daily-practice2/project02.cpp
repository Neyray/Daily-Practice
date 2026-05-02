//给定一棵二叉树，将其镜像翻转（左右子树交换），然后输出翻转后的先序遍历序列
//一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int val;

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

//镜像翻转
void mirrorReverse(Node* root) {
	if (root == NULL)return;

	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	mirrorReverse(root->left);
	mirrorReverse(root->right);
}

void print(Node* root) {
	if (root == NULL)return;

	cout << root->val << " ";
	print(root->left);
	print(root->right);
}

int main() {
	string str;
	getline(cin,str);
	stringstream ss(str);

	string num;
	vector<int>node;
	while(getline(ss,num,' ')){
		if(!num.empty() && num.back()=='\r'){
			num.pop_back();
		}
		if(num.empty())continue;

		node.push_back(stoi(num));
	}

	int idx = 0;
	Node* root = buildTree(node, idx);

	mirrorReverse(root);
	print(root);

	return 0;
}