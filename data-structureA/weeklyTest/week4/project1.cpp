//先序遍历输出二叉树 bt 中所有结点的层次
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;

struct Node {
	char val;
	int level;
	Node* left;
	Node* right;

	Node(char c) :val(c), left(NULL), right(NULL), level(0) {}
};


Node* createTree() {
	int n;
	cin >> n;
	cin.ignore();

	map<char, Node*>nodes;

	Node* root = NULL;
	int i = 1;

	//遍历n次
	while (i <= n) {
		string str;
		getline(cin, str);
		stringstream ss(str);
		char ch1, ch2, ch3;
		ss >> ch1 >> ch2 >> ch3;

		if (nodes.find(ch1) == nodes.end()) {
			nodes[ch1] = new Node(ch1);
		}
		Node* curr = nodes[ch1];

		if (ch2 != '#') {
			if (nodes.find(ch2) == nodes.end()) {
				nodes[ch2] = new Node(ch2);
			}
			curr->left = nodes[ch2];
		}

		if (ch3 != '#') {
			if (nodes.find(ch3) == nodes.end()) {
				nodes[ch3] = new Node(ch3);
			}
			curr->right = nodes[ch3];
		}

		if (i == 1)root = curr;
		i++;
	}
	return root;
}


void setLevel(Node* root) {
	queue<Node*>q;
	q.push(root);

	int level = 1;

	while (!q.empty()) {
		int levelsize = q.size();

		for (int i = 0; i < levelsize; ++i) {
			Node* curr = q.front(); q.pop();
			curr->level = level;

			if (curr->left != NULL)q.push(curr->left);
			if (curr->right != NULL)q.push(curr->right);
		}
		level++;
	}
}

//先序遍历
void preorder(Node* root) {
	if (root == NULL)return;

	cout << root->val << " " << root->level << endl;
	preorder(root->left);
	preorder(root->right);
}

//也可以直接在先序遍历里输出层次
//先序遍历虽然不是按层访问，但递归过程中天然知道“从根走了几步”。
void preorder2(Node* root, int level) {
	if (root == NULL) return;

	cout << root->val << " " << level << endl;
	preorder2(root->left, level + 1);
	preorder2(root->right, level + 1);
}

int main() {
	Node* root = createTree();

	setLevel(root);

	preorder(root);

	return 0;
}