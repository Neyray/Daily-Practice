#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <tuple>

using namespace std;

struct Edge {
    int to;
    int weight;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "error" << endl;
    }
    int n, m;
    inFile >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        inFile >> u >> v >> w;
        edges[i] = make_tuple(u, v, w);
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }

    const int INF = numeric_limits<int>::max();
    int best = INF;

    vector<int> dist(n + 1);
    vector<bool> used(n + 1);

    // 枚举要“删除”的那条边 eid
    for (int eid = 0; eid < m; eid++) {
        int su, sv, sw;
        tie(su, sv, sw) = edges[eid];

        // 初始化 Dijkstra
        fill(dist.begin(), dist.end(), INF);
        fill(used.begin(), used.end(), false);
        dist[su] = 0;

        for (int iter = 0; iter < n; iter++) {
            int u = -1, minD = INF;
            for (int i = 1; i <= n; i++) {
                if (!used[i] && dist[i] < minD) {
                    minD = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            used[u] = true;
            if (u == sv) break;  // 找到 sv，就可以结束了

            // 松弛
            for (auto& e : adj[u]) {
                int v = e.to;
                // 跳过被“删除”的那条边
                if (e.id == eid) continue;
                // 跳过从 su 直接到 sv 的任何一条边，避免 k=2 的平行边环
                if (u == su && v == sv) continue;

                // 防止 INF + e.weight 溢出
                if (dist[u] != INF && dist[u] + e.weight < dist[v]) {
                    dist[v] = dist[u] + e.weight;
                }
            }
        }

        if (dist[sv] < INF) {
            best = min(best, dist[sv] + sw);
        }
    }

    if (best < INF) {
        cout << best << "\n";
    } else {
        cout << "It's impossible.\n";
    }

    return 0;
}



