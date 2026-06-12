//prim算法
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAXV 1005
#define INF 0x3f3f3f3f

class MatGraph {
public:
	int n;
	int e;
	int matrix[MAXV][MAXV];

	MatGraph() {
		for (int i = 0; i < MAXV; ++i) {
			for (int j = 0; j < MAXV; ++j) {
				if (i == j)matrix[i][j] = 0;
				else matrix[i][j] = INF;
			}
		}
	}

	void createGraph(vector<vector<int>>edges, int n, int m) {
		this->n = n;
		this->e = m;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				this->matrix[i][j] = edges[i][j];
			}
		}
	}
};

int Prim(MatGraph& G, int v, vector<int>& ans) {
	//从v开始使用prim算法构造最小生成树
	int closest[MAXV];
	int lowcost[MAXV];

	//vector<int>ans;
	int result = 0;

	for (int i = 1; i <= G.n; ++i) {
		closest[i] = v;
		lowcost[i] = G.matrix[v][i];
	}

	lowcost[v] = 0;
	ans.push_back(v);

	//总共要构造n-1个节点
	for (int i = 1; i < G.n; ++i) {
		int min = INF;
		int k = -1;//k表示找到的那个节点

		for (int j = 1; j <= G.n; ++j) {
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		if (k != -1) {
			//找到了最小的节点
			ans.push_back(k);
			result += min;

			lowcost[k] = 0;

			//每添加一个节点到生成树就要更新剩余节点
			for (int j = 1; j <= G.n; ++j) {
				if (lowcost[j] != 0 && G.matrix[k][j] < lowcost[j]) {
					lowcost[j] = G.matrix[k][j];
					closest[j] = k;
				}
			}
		}
		else {
			return result;
		}
	}
	return result;
}

int main() {
	int n;
	int m;
	cin >> n >> m;

	vector<vector<int>>edges(MAXV, vector<int>(MAXV, 0));
	for (int i = 0; i < MAXV; ++i) {
		for (int j = 0; j < MAXV; ++j) {
			if (i == j)edges[i][j] = 0;
			else edges[i][j] = INF;
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a][b] = c;
		edges[b][a] = c;
	}

	MatGraph G;
	G.createGraph(edges, n, m);

	vector<int>ans;
	int v = 1;
	int result = Prim(G, v, ans);

	if (ans.size() < n)cout << "-1";
	else cout << result;

	return 0;
}