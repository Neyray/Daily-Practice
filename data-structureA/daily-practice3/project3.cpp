//图的深度优先遍历
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

#define MAXV 1005
#define INF 0x3f3f3f3f

//采用邻接矩阵
class MatGraph {
public:
	int n;//顶点数
	int e;//边数
	int matrix[MAXV][MAXV];

	//初始化
	MatGraph(int n, int m) {
		this->n = n;
		this->e = m;

		//对矩阵进行初始化
		for (int i = 0; i < MAXV; ++i) {
			for (int j = 0; j < MAXV; ++j) {
				if (i == j)matrix[i][j] = -1;
				else matrix[i][j] = INF;
			}
		}
	}

	void createMatrix() {
		//总共输入e行
		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;
			matrix[a][b] = 1;//表示两点之间有边
			matrix[b][a] = 1;//！！！一定注意，无向图需要两边对称
		}
	}
};

void DFS(MatGraph& G, int start) {
	int visited[MAXV];
	memset(visited, 0, sizeof(visited));

	stack<int>st;
	st.push(start);
	//先输出开始节点
	cout << start << " ";
	visited[start] = 1;

	while (!st.empty()) {
		int u = st.top();
		bool bl = false;

		//对从u开始的边进行遍历，也就是对第u行进行遍历
		for (int i = 1; i <= G.n; ++i) {
			//对每个结点访问
			if (G.matrix[u][i] == 1 && !visited[i]) {
				cout << i << " ";
				bl = true;
				visited[i] = 1;

				st.push(i);
				break;
			}
		}
		if (!bl)st.pop();
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	MatGraph G(n, m);
	G.createMatrix();

	int start;
	cin >> start;

	DFS(G, start);

	return 0;
}