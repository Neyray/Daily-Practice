#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 邻接矩阵，节点编号从 1 到 n，所以开 n + 1
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    // 邻接表
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // 无向图：矩阵两边都标记
        matrix[u][v] = 1;
        matrix[v][u] = 1;

        // 无向图：邻接表两边都加入
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 输出邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }

    // 邻接表按升序排序
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 输出邻接表
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (int v : adj[i]) {
            cout << " " << v;
        }
        cout << endl;
    }

    return 0;
}
