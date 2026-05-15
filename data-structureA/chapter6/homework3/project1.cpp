//编码前缀问题
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct BTNode {
	bool isEnd;
	BTNode* left;
	BTNode* right;

	BTNode() {
		isEnd = false;
		left = NULL;
		right = NULL;
	}
};

bool insertCode(BTNode* root, const string& str) {
	BTNode* p = root;
	int n = str.size();

	for (int i = 0; i < n; ++i) {
		//1.现有短编码是当前长编码的前缀
		if (p->isEnd)return false;

		if (str[i] == '0') {
			//只有不匹配的情况才会新建节点
			if (p->left == NULL)p->left = new BTNode();
			p = p->left;//更新节点位置
			//之所以不直接break，是因为后面也要与当前的树比较，所以必须把树建完
		}
		else if (str[i] == '1') {
			if (p->right == NULL)p->right = new BTNode();
			p = p->right;
		}
	}
	//此时已经把树建好了
	//2.存在完全相同的编码
	if (p->isEnd)return false;

	//3.当前短编码是已有长编码的前缀
	if (p->left != NULL || p->right != NULL)return false;

	//其余情况，更新isEnd值
	p->isEnd = true;
	return true;
}

int main() {
	string str;
	BTNode* root = new BTNode();
	bool flag = true;

    ifstream inFile("in.txt"); 

	while (inFile >> str) {
		if (str == "9")break;

		if (flag) {
			if (!insertCode(root, str)) {
				flag = false;
				break;//后面没必要看了
			}
		}
	}

	if (flag)cout << "Y";
	else cout << "N";

	return 0;
}