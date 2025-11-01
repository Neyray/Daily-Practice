#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    queue<int> q;
    vector<int> result;

    // 计算入度
    for (auto& edges : adj)
        for (int v : edges)
            inDegree[v]++;

    // 初始化队列
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u])
            if (--inDegree[v] == 0)
                q.push(v);
    }

    return result;
}

int main() {
    const int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = { 2, 0 };
    adj[4] = { 0, 1 };
    adj[2] = { 3 };
    adj[3] = { 1 };

    vector<int> order = topologicalSort(V, adj);

    cout << "拓扑排序结果：";
    for (int v : order) cout << v << " ";
    return 0;
}