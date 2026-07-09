#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

const int INF = INT_MAX;

// 用 Dijkstra 求 src 到所有节点的最短时间，
// 返回传播到最远节点所需的时间；如果有节点不可达，返回 INF。
int findMinTime(int src, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    // 小顶堆：pair<当前时间, 节点>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;   // 修正：strc -> src
    pq.push({ 0, src });

    while (!pq.empty()) {   // 补全括号
        // 不使用 structured binding，兼容老编译器
        pair<int, int> top = pq.top();
        int d = top.first;
        int u = top.second;
        pq.pop();

        if (d > dist[u]) continue;
        for (auto& e : graph[u]) {
            int v = e.first, w = e.second;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }   // while 结束

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return INF;    // 有节点不可达
        maxTime = max(maxTime, dist[i]);
    }
    return maxTime;
}

int main() {
    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "Failed to open in.txt\n";
        return 1;
    }

    int n;
    // 多组数据，读到 EOF
    while (inFile >> n) {
        vector<vector<pair<int, int>>> graph(n + 1);

        // 读每个经纪人的联系人列表
        for (int i = 1; i <= n; i++) {
            int m;
            inFile >> m;
            for (int j = 0; j < m; j++) {
                int v, t;
                inFile >> v >> t;
                graph[i].emplace_back(v, t);
            }
        }

        int bestSrc = -1, bestTime = INF;
        for (int src = 1; src <= n; src++) {
            int t = findMinTime(src, n, graph);
            if (t < bestTime) {
                bestTime = t;
                bestSrc = src;
            }
        }

        if (bestTime == INF) {
            cout << "disjoint\n";
        }
        else {
            cout << bestSrc << " " << bestTime << "\n";
        }
    }

    return 0;
}

