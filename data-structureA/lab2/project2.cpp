//括号表示法输入
//输出从右到左的节点，中序遍历序列
//！！！递归可以让函数自己处理空；但只要你要访问空指针的成员，或者把它放进队列后还要访问，就必须先判断。
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v) :val(v), left(NULL), right(NULL) {}
};

Node* createTree(string str) {
	int n = str.length();
	int k = 0;
	int i = 0;
	stack<Node*>st;
	Node* root = NULL;
	Node* p = NULL;//用来暂存节点

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
			//考虑负数
			int sign = 1;
			if (str[i] == '-') {
				sign = -1;
				i++;
			}

			int num = 0;
			while (isdigit(str[i])) {
				num = num * 10 + (str[i] - '0');
				i++;
			}
            num=sign*num;
            
			//此时的i是下一个字符，所以就不需要在最后更新i
			p = new Node(num);

			if (root == NULL) {
				root = p;
			}
			else {
				if (k == 1)st.top()->left = p;
				else if (k == 2)st.top()->right = p;
			}
		}
	}
	return root;
}

//从右到左输出叶子节点
void func(Node* root) {
	if (root == NULL)return;
	if (root->left == NULL && root->right == NULL)cout << root->val << " ";

	//从右到左
	func(root->right);
	func(root->left);
}

//中序遍历
void inorder(Node* root) {
	stack<Node*>st;
	Node* p = root;

	while (!st.empty() || p != NULL) {
		while (p != NULL) {
			st.push(p);
			p = p->left;
		}

		if (!st.empty()) {
			//从下到上进行回溯，达到了左根右的效果
			p = st.top(); st.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
}

int main() {
	string str;
	cin >> str;

	Node* root = createTree(str);
	func(root);
	cout << endl;
	inorder(root);

	return 0;
}