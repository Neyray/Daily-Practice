//图的广度优先遍历
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define MAXV 1005
#define INF 0x3f3f3f3f

//采用邻接表存储
struct ArcNode {
	int adjvex;//当前节点的标号
	ArcNode* next;
};

struct HNode {
	ArcNode* firstarc;
};

class AdjGraph {
public:
	int n;//顶点数
	int e;//边数
	HNode adjlist[MAXV];

	AdjGraph(int n, int m) {
		this->n = n;
		this->e = m;

		for (int i = 0; i < MAXV; ++i) {
			adjlist[i].firstarc = NULL;
		}
	}

	void createGraph(vector<vector<int>>& matrix) {
		for (int i = 1; i <= n; ++i) {
			for (int j = n; j >= 1; --j) {
				if (matrix[i][j] == 1) {
					ArcNode* p = new ArcNode;
					p->adjvex = j;

					p->next = adjlist[i].firstarc;
					adjlist[i].firstarc = p;
				}
			}
		}
	}
};

void BFS(AdjGraph& G, int start) {
	int visited[MAXV];
	memset(visited, 0, sizeof(visited));

	queue<int>q;
	q.push(start);
	visited[start] = 1;

	cout << start << " ";

	while (!q.empty()) {
		int u = q.front(); q.pop();
		//从它第一个邻接节点开始访问
		ArcNode* p = G.adjlist[u].firstarc;
		while (p != NULL) {
			//由于一定是邻接点，所以只需要判断是否访问过了
			int w = p->adjvex;
			if (!visited[w]) {
				cout << w << " ";
				visited[w] = 1;

				q.push(w);
			}
			p = p->next;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>>matrix(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

        //！！！无向图一定要注意
        //数据量过大可能会溢出，用vector邻接表，再逆序
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	AdjGraph G(n, m);
	G.createGraph(matrix);

	int s;
	cin >> s;
	BFS(G, s);

	return 0;
}