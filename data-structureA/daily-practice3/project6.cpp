//！！！核心：在外面维护visited数组，之后主函数遍历所有节点，依次递增，直到遇到DFS没遍历到的节点，就从这个点继续DFS
//连通分量问题
#include <iostream>
#include <vector>
using namespace std;

#define MAXV 1005

int visited[MAXV];
vector<int>adjlist[MAXV];
int n, m;

void DFS(int v) {
	//从v开始遍历
	visited[v] = 1;

	//对每一个节点的邻接节点遍历
	//！！！注意：不是i<n，因为这里是二维数组，所以需要从0开始遍历，下标不是节点号，大小是邻接点的个数
	for (int i = 0; i < adjlist[v].size(); ++i) {
		int w = adjlist[v][i];

		if (!visited[w]) {
			visited[w] = 1;
			DFS(w);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		visited[i] = 0;//表示没有访问过
	}

	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			count++;
			DFS(i);//从i开始深度优先遍历
		}
	}

	if (count == 1)cout << "YES";
	else cout << "NO " << count;

	return 0;
}