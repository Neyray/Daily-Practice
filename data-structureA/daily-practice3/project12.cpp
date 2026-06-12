//Dijkstra算法
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

	//输完第一行了
	void createGraph(int n, int m) {
		this->n = n;
		this->e = m;

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			//有向图
			this->matrix[a][b] = c;
		}
	}
};

vector<int> Dijkstra(MatGraph& G, int v) {
	vector<int>dist(MAXV);
	int S[MAXV];

	//进行初始化
	for (int i = 1; i <= G.n; ++i) {
		dist[i] = G.matrix[v][i];
		S[i] = 0;
	}
	dist[v] = 0;
	S[v] = 1;

	//找到n-1个点
	for (int i = 1; i < G.n; ++i) {
		int min = INF;
		int k = -1;

		for (int j = 1; j <= G.n; ++j) {
			if (S[j] == 0 && dist[j] < min) {
				min = dist[j];
				k = j;
			}
		}
		if (k == -1)break;
		//找到了目前离的最近的点
		S[k] = 1;

		//更新别的点离v的最短距离
		for (int j = 1; j <= G.n; ++j) {
			if (S[j] == 0 && dist[k] + G.matrix[k][j] < dist[j]) {
				dist[j] = dist[k] + G.matrix[k][j];
			}
		}
	}
	return dist;
}
//！！！
MatGraph G;//为什么放在外面差距会这么大？
//1.写在main里面会分配到栈区，空间小
//2.写在外部，会分配到全局静态区

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	//MatGraph G;
	G.createGraph(n, m);

	vector<int>result = Dijkstra(G, v);

	for (int i = 1; i <= G.n; ++i) {
		if (result[i] == INF)cout << "-1" << " ";
		else cout << result[i] << " ";
	}

	return 0;
}