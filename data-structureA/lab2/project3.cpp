//判断是否在同层次，并且输出除它以外的叶子节点
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Node {
	char val;
	Node* left;
	Node* right;

	Node(char v) :val(v), left(NULL), right(NULL) {}
};

Node* createTree(string str) {
	int n = str.length();
	int i = 0;
	int k = 0;
	Node* root = NULL;
	Node* p = root;
	stack<Node*>st;

	while (i < n) {
		if (str[i] == '(') {
			st.push(p);
			k = 1;
			i++;
		}
		else if (str[i] == ')') {
			st.pop();
			k = 0;
			i++;
		}
		else if (str[i] == ',') {
			k = 2;
			i++;
		}
		else {
			char num = str[i];

			p = new Node(num);
			if (root == NULL)root = p;
			else {
				if (k == 1)st.top()->left = p;
				if (k == 2)st.top()->right = p;
			}
			i++;
		}
	}
	return root;
}

Node* root1 = NULL;
Node* root2 = NULL;

//判断是不是同一代
//进行层序遍历
bool func1(Node* root, char target1, char target2) {
	queue<Node*>q;
	q.push(root);

	int count = 0;
	while (!q.empty()) {
		int levelSize = q.size();
		//每一层
		for (int i = 0; i < levelSize; ++i) {
			//每一次执行出队操作
			Node* curr = q.front(); q.pop();

			//只关心是不是目标字符
			if (curr->val == target1) {
				count++;
				root1 = curr;
			}
			if (curr->val == target2) {
				count++;
				root2 = curr;
			}

			//将后继节点入队列
			if (curr->left != NULL)q.push(curr->left);
			if (curr->right != NULL)q.push(curr->right);
		}
		if (count == 2)break;
		count = 0;
	}
	return count == 2;
}

void func2(Node* root,string& str) {
	if (root == NULL)return;
	if (root->left == NULL && root->right == NULL)str += root->val;

	func2(root->left, str);
	func2(root->right, str);
}

int main() {
	string str;
	cin >> str;

	char target1, target2;
	cin >> target1 >> target2;

	Node* root = createTree(str);

	if (func1(root, target1, target2)) cout << "True";
	else cout << "False";

	cout << endl;
	string str1, str2;

	//！！！重点：不处理本身就是叶节点的方法是分别处理左子树和右子树
	// 只统计 target1 的子孙，不统计 target1 自己
	if (root1 != NULL) {
		func2(root1->left, str1);
		func2(root1->right, str1);
	}

	// 只统计 target2 的子孙，不统计 target2 自己
	if (root2 != NULL) {
		func2(root2->left, str2);
		func2(root2->right, str2);
	}


	//输出
	if (!str1.empty()) {
		cout << '[';
		for (int i = 0; i < str1.length(); ++i) {
			cout << str1[i];
		}
		cout << ']';
	}

	if (!str2.empty()) {
		cout << '[';
		for (int i = 0; i < str2.length(); ++i) {
			cout << str2[i];
		}
		cout << ']';
	}

	return 0;
}