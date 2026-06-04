//输出二叉树的边界
//注意：！！！左边界不是只走左边，而是有左走左，没左走右
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
	string val;//多位数看成字符串
	Node* left;
	Node* right;

	Node(string v) {
		val = v;
		left = NULL;
		right = NULL;
	}
};

// 修改：新增函数，判断是不是叶子节点
bool isLeaf(Node* p) {
	return p != NULL && p->left == NULL && p->right == NULL;
}

Node* buildTree() {
	Node* root = NULL;

	map<string, Node*>nodes;

	int n; // 修改：long long 改为 int
	cin >> n;
	//cin.ignore();
	for (int i = 1; i <= n; ++i) { // 修改：long long 改为 int
		string ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;

		//ch1肯定不是#
		if (nodes.find(ch1) == nodes.end()) {
			nodes[ch1] = new Node(ch1);
		}
		Node* curr = nodes[ch1];

		if (ch2 != "#") {
			if (nodes.find(ch2) == nodes.end()) {
				nodes[ch2] = new Node(ch2);
			}
			curr->left = nodes[ch2];
		}

		if (ch3 != "#") {
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

//左边界
void output1(Node* root, vector<string>& ans) {
	Node* p = root;

	while (p != NULL) {
		//输出外围左端点
		// 修改：左边界不加入叶子，叶子统一交给 output2 处理，防止重复
		if (!isLeaf(p)) {
			ans.push_back(p->val);
		}

		// ！！！修改：左边界不是只走左边，而是有左走左，没左走右
		if (p->left != NULL) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	//ans的最后一个不要输出
}

//叶子节点
void output2(Node* root, vector<string>& ans) {
	if (root == NULL)return;

	if (root->left == NULL && root->right == NULL) {
		ans.push_back(root->val);
	}

	output2(root->left, ans);
	output2(root->right, ans);
}

//右边界
void output3(Node* root, vector<string>& ans) {
	Node* p = root;

	while (p != NULL) {
		// 修改：右边界不加入叶子，叶子统一交给 output2 处理，防止重复
		if (!isLeaf(p)) {
			ans.push_back(p->val);
		}

		// 修改：右边界不是只走右边，而是有右走右，没右走左
		if (p->right != NULL) {
			p = p->right;
		}
		else {
			p = p->left;
		}
	}
	//ans的第一个节点和最后一个节点不输出，倒序输出
}

int main() {
	Node* root = buildTree();

	vector<string>ans1, ans2, ans3;

	output1(root, ans1);
	output2(root, ans2);
	output3(root, ans3);

	// 修改：统一放到 result 里，避免重复和下标越界问题
	vector<string> result;

	//输出
	for (int i = 0; i < (int)ans1.size(); ++i) {
		result.push_back(ans1[i]);
	}

	for (int i = 0; i < (int)ans2.size(); ++i) {
		result.push_back(ans2[i]);
	}

	// 修改：ans3[0] 是根，不能输出；右边界需要倒序输出
	for (int i = (int)ans3.size() - 1; i >= 1; --i) {
		result.push_back(ans3[i]);
	}

	// 修改：统一控制空格，避免行尾多空格
	for (int i = 0; i < (int)result.size(); ++i) {
		if (i != 0) cout << " ";
		cout << result[i];
	}

	return 0;
}