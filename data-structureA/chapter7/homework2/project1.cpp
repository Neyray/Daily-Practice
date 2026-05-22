//网络延迟时间
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f;

class MatGraph {
public:
	int matrix[MAXV][MAXV];
	int n, e;//顶点数，边数

	//默认初始化
	MatGraph() {
		n = e = 0;
		for (int i = 0; i < MAXV; ++i) {
			for (int j = 0; j < MAXV; ++j) {
				matrix[i][j] = INF;
			}
		}
	}

	//根据矩阵构建图
	void createGraph(int a[][MAXV], int n, int e) {
		this->n = n;
		this->e = e;

		//由于是有向图，所以需要一个个遍历
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				matrix[i][j] = a[i][j];
			}
		}
	}
};

int networkDelayTime(MatGraph& G, int N, int K) {
	//网络结点的总个数N，以及信号发送的起始结点K
	//采用Dijkstra算法求出最短路径
	int dist[MAXV];//表示到该点的最短距离
	int visited[MAXV];//表示是否属于已生成路径

	//进行初始化
	for (int i = 1; i <= N; ++i) {
		dist[i] = G.matrix[K][i];
		visited[i] = 0;
	}
	dist[K] = 0;
	visited[K] = 1;

	//遍历剩下的N-1个节点
	for (int i = 1; i < N; ++i) {
		int min = INF;
		int target = -1;

		//1.找到距离最短的节点
		//对N个节点都进行遍历
		for (int j = 1; j <= N; ++j) {
			if (!visited[j] && dist[j] < min) {
				min = dist[j];
				target = j;
			}
		}

		if (target == -1 || min == INF)return -1;
		visited[target] = 1;//加入现有路径

		//2.更新现有的节点
		//为什么从1开始？没有0节点
		for (int j = 1; j <= N; ++j) {
			if (!visited[j] && G.matrix[target][j] < INF && dist[target] + G.matrix[target][j] < dist[j]) {
				dist[j] = G.matrix[target][j] + dist[target];
			}
		}
	}

	int ans = 0;
	//此时的dist存储了不同节点的最短路径
	for (int i = 1; i <= N; ++i) {
		ans = max(ans, dist[i]);
	}
	return ans;
}

int main() {
	int N, K;
	cin >> N >> K;
	cin.ignore();

	MatGraph G;
	int m[MAXV][MAXV];
	for (int i = 0; i < MAXV; ++i) {
		for (int j = 0; j < MAXV; ++j) {
			//第62行的比较，必须让没有边的权值为INF
			m[i][j] = INF;//INF表示两点之间没有边
		}
	}

	string str;
	int e = 0;
	while (getline(cin, str) && str!="") {
		stringstream ss(str);
		int a, b, c;
		ss >> a >> b >> c;
		//！！！输入建图已经是“用节点值当下标”了
		m[a][b] = c;
		e++;
	}

	G.createGraph(m, N, e);

	cout << networkDelayTime(G, N, K);

	return 0;
	
}