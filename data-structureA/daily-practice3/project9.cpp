//！！！一定要注意爆栈问题
//1.将G定义在main函数外面
//2.引用传递参数
//3.邻接矩阵边读边创建，没必要引入中间变量edges
//kruskal算法
#include <iostream>
#include <vector>
#include <algorithm>
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

	void createGraph(vector<vector<int>>& edges, int n, int m) {
		this->n = n;
		this->e = m;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				this->matrix[i][j] = edges[i][j];
			}
		}
	}
};

//Kruskal算法
struct Edge {
	int u;
	int v;
	int w;
	Edge(int u, int v, int w)    // 构造函数
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int Kruskal(MatGraph& G,int& count) {
	vector<Edge>arr;

	for (int i = 1; i <= G.n; ++i) {
		for (int j = i + 1; j <= G.n; ++j) {
			if (G.matrix[i][j] != 0 && G.matrix[i][j] < INF) {
				arr.push_back(Edge(i, j, G.matrix[i][j]));
			}
		}
	}

	sort(arr.begin(), arr.end(),
		[](Edge e1, Edge e2) {return e1.w < e2.w; });

	int vset[MAXV];
	for (int i = 1; i <= G.n; ++i) {
		vset[i] = i;
	}

	int k = 1;
	int j = 0;
	int result = 0;

	while (k < G.n && j < arr.size()) {
		int u1 = arr[j].u;
		int u2 = arr[j].v;

		int w1 = vset[u1];
		int w2 = vset[u2];
		if (w1 != w2) {
			count++;
			result += arr[j].w;

			for (int i = 1; i <= G.n; ++i) {
				if (vset[i] == w2) {
					vset[i] = w1;
				}
			}
			k++;
		}
		j++;
	}
	return result;
}

MatGraph G;

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

	G.createGraph(edges, n, m);

	int count = 0;
	int result = Kruskal(G, count);

	if (count < n - 1)cout << "-1";
	else cout << result;

	return 0;
}