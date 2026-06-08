//表达式树求值
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node {
	int id;
	int type;          // 0 表示数字，1 表示运算符
	string value;      // 用 string 存，支持多位整数和运算符

	Node* left;
	Node* right;

	bool flag;         // 判断是否可能是根节点

	Node(int id, int type, string v)
		: id(id), type(type), value(v), left(NULL), right(NULL), flag(true) {
	}
};

Node* buildTree() {
	Node* root = NULL;
	map<int, Node*> nodes;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int id, type, left, right;
		string value;

		cin >> id >> type >> value >> left >> right;

		if (nodes.find(id) == nodes.end()) {
			nodes[id] = new Node(id, type, value);
		}
		else {
			nodes[id]->type = type;
			nodes[id]->value = value;
		}

		Node* curr = nodes[id];

		if (left != -1) {
			if (nodes.find(left) == nodes.end()) {
				nodes[left] = new Node(left, 0, "");
			}
			nodes[left]->flag = false;
			curr->left = nodes[left];
		}

		if (right != -1) {
			if (nodes.find(right) == nodes.end()) {
				nodes[right] = new Node(right, 0, "");
			}
			nodes[right]->flag = false;
			curr->right = nodes[right];
		}
	}

	// 最后再统一找根节点，避免输入顺序导致 root 判断错误
	for (auto it : nodes) {
		if (it.second->flag == true) {
			root = it.second;
			break;
		}
	}

	return root;
}

//后序遍历变种思想
int evaluate(Node* root){
    if(root==NULL)return 0;

    if(root->type==0)return stoi(root->value);

    int leftVal=evaluate(root->left);
    int rightVal=evaluate(root->right);

    if(root->value=="+"){
        return leftVal+rightVal;
    }
    else if(root->value=="-"){
        return leftVal-rightVal;
    }
    else if(root->value=="*"){
        return leftVal*rightVal;
    }
    else if(root->value=="/"){
        return leftVal/rightVal;
    }
    return 0;
}

int main() {
	Node* root = buildTree();

	cout << evaluate(root);

	return 0;
}