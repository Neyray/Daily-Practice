//输出后序序列的叶子节点
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;

	Node(char v) {
		val = v;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	Node* root = NULL;

	map<char, Node*>nodes;

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; ++i) {
		string str;
		getline(cin, str);
		stringstream ss(str);

		char ch1, ch2, ch3;
		ss >> ch1 >> ch2 >> ch3;

		//ch1肯定不是#
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

		if (root == NULL) {
			root = curr;
		}
	}
	return root;
}

void postorder(Node* r) {
	if (r == NULL)return;
	postorder(r->left);
	postorder(r->right);
	if (r->left == NULL && r->right == NULL)cout << r->val;

}

int main() {
	Node* root = buildTree();

	postorder(root);

	return 0;
}
