//计算二叉树的高度
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
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

int getHeight(Node* root) {
	//设置退出条件
	if (root == NULL)return 0;

	return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getHeightBFS(Node* root) {
	queue<Node*>q;
	q.push(root);
	int height = 0;

	while (!q.empty()) {
		//levelsize是每一层的节点数量
		int levelsize = q.size();
		for (int i = 0; i < levelsize; ++i) {
			Node* curr = q.front();
			q.pop();

			if (curr->left != NULL)q.push(curr->left);
			if (curr->right != NULL)q.push(curr->right);
		}
		//每一侧最外层循环就是对二叉树每一层的处理
		height++;
	}

	return height;
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

	cout << getHeight(root);

	return 0;
}