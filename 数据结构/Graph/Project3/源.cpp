#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_V = 5;
vector<vector<int>> adj(MAX_V);

void bfs(int start) {
    vector<bool> visited(MAX_V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    // 构建图
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3 };
    adj[2] = { 0, 4 };
    adj[3] = { 1 };
    adj[4] = { 2 };

    cout << "BFS遍历结果：";
    bfs(0);
    return 0;
}