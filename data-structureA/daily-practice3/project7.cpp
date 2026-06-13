// 判断最小生成树唯一性
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXV 105
#define INF 0x3f3f3f3f

struct Edge {
    int u, v, w;
};

// 使用邻接矩阵
class MatGraph {
public:
    int n, e;
    int edges[MAXV][MAXV];
    vector<Edge> edgeList;

    MatGraph() {
        for (int i = 0; i < MAXV; ++i) {
            for (int j = 0; j < MAXV; ++j) {
                if (i == j) edges[i][j] = 0;
                else edges[i][j] = INF;
            }
        }
    }

    void createGraph(int n, int m) {
        this->n = n;
        this->e = m;

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;

            edges[a][b] = c;
            edges[b][a] = c;

            edgeList.push_back({a, b, c});
        }
    }
};

MatGraph G;

// MST 的邻接表
vector<pair<int, int>> tree[MAXV];

// 判断某条边是否在 MST 中
bool inMST[MAXV][MAXV];

// Prim 求一棵 MST
int prim(MatGraph& G, int v) {
    int closest[MAXV];
    int lowcost[MAXV];
    bool visited[MAXV];

    for (int i = 1; i <= G.n; ++i) {
        closest[i] = -1;
        lowcost[i] = INF;
        visited[i] = false;
    }

    lowcost[v] = 0;

    int result = 0;

    for (int i = 1; i <= G.n; ++i) {
        int minCost = INF;
        int k = -1;

        // 找当前离 MST 最近的点
        for (int j = 1; j <= G.n; ++j) {
            if (!visited[j] && lowcost[j] < minCost) {
                minCost = lowcost[j];
                k = j;
            }
        }

        // 图不连通
        if (k == -1) {
            return INF;
        }

        visited[k] = true;
        result += minCost;

        // 如果 closest[k] != -1，说明选中了边 closest[k] - k
        if (closest[k] != -1) {
            int u = closest[k];
            int w = G.edges[u][k];

            tree[u].push_back({k, w});
            tree[k].push_back({u, w});

            inMST[u][k] = true;
            inMST[k][u] = true;
        }

        // 更新其他点到 MST 的最短边
        for (int j = 1; j <= G.n; ++j) {
            if (!visited[j] && G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
                closest[j] = k;
            }
        }
    }

    return result;
}

// 在 MST 中找 u 到 v 路径上的最大边权
bool dfsMaxEdge(int u, int target, int parent, int& maxEdge) {
    if (u == target) {
        return true;
    }

    for (auto item : tree[u]) {
        int next = item.first;
        int weight = item.second;

        if (next == parent) continue;

        if (dfsMaxEdge(next, target, u, maxEdge)) {
            maxEdge = max(maxEdge, weight);
            return true;
        }
    }

    return false;
}

// 判断 MST 是否唯一
bool isUniqueMST(MatGraph& G) {
    for (auto e : G.edgeList) {
        int u = e.u;
        int v = e.v;
        int w = e.w;

        // MST 中的边不用检查
        if (inMST[u][v]) continue;

        int maxEdge = -1;

        // 找 MST 中 u 到 v 路径上的最大边
        dfsMaxEdge(u, v, -1, maxEdge);

        // 如果非树边权值 == 路径上的最大边权，则可以替换，MST 不唯一
        if (maxEdge == w) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    G.createGraph(n, m);

    int result = prim(G, 1);

    bool unique = isUniqueMST(G);

    if (unique) {
        cout << "YES" << " " << result;
    } else {
        cout << "NO" << " " << result;
    }

    return 0;
}