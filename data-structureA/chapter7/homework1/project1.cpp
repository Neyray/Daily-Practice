//邻接矩阵+广度优先遍历判断两点之间是否有路径
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int num;
	int value;//表示访问位

	Node(int n) :num(n), value(0) {}
	Node(int n, int i) :num(n), value(i) {}
};

bool isConnected(vector<vector<int>>& matrix, vector<Node*>& res, int start, int end) {
	int n = matrix.size();

	//从p开始看路径
	//广度优先使用队列
	queue<Node*>q;
	q.push(res[start]);//先把起点入队列
	res[start]->value = 1;

	while (!q.empty()) {
		//curr表示当前的节点
		Node* curr = q.front(); q.pop();
		int target = curr->num;//target表示当前节点的下标

		if (target == end)return true;

		//在每一行中找与这个节点有连接的点
		for (int i = 0; i < n; ++i) {
			if (matrix[target][i] == 1 && res[i]->value == 0) {
				//此时需要入队
				res[i]->value = 1;
				q.push(res[i]);
			}
		}
		
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>>matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	vector<Node*>res;
	for (int i = 0; i < n; ++i) {
		res.push_back(new Node(i));
	}

	int start, end;
	cin >> start;
	cin >> end;

	if (isConnected(matrix, res, start, end))cout << "TRUE";
	else cout << "FALSE";

	return 0;
}