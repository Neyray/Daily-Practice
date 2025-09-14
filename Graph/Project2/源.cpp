#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 5;
vector<vector<int>> adj(MAX_V);
vector<bool> visited(MAX_V, false);

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    // 构建图
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3 };
    adj[2] = { 0, 4 };
    adj[3] = { 1 };
    adj[4] = { 2 };

    cout << "DFS遍历结果：";
    dfs(0);
    return 0;
}