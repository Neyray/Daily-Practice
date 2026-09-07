// ============================================================
// Topic : Disjoint Set Union / Minimum Spanning Tree
// Dir   : Algorithm/dsu-mst/
//
// 并查集解决的是「动态连通性」：
//   - 两个点在不在同一个集合里？   find(x) == find(y)
//   - 把两个集合合并              unite(x, y)
//
// 两个优化必须一起用：
//   路径压缩 (find 时把路径上所有点直接挂到根)
//   按秩 / 按大小合并 (小树挂到大树下)
//   -> 单次操作近似 O(α(n))，α 是反阿克曼函数，实际可当常数
//
// 最小生成树：
//   Kruskal —— 边排序 + 并查集判环，适合稀疏图  O(E log E)
//   Prim    —— 从点出发 + 优先队列扩展，适合稠密图 O(E log V) / O(V^2)
// ============================================================

#include <algorithm>
#include <climits>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 1. 并查集模板（路径压缩 + 按大小合并）
// ------------------------------------------------------------
class DSU {
public:
    explicit DSU(int n) : parent(n), size_(n, 1), count_(n) {
        iota(parent.begin(), parent.end(), 0);   // 初始每个点自成一个集合
    }

    int find(int x) {                            // 迭代式路径压缩，不怕爆栈
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];       // 路径减半
            x = parent[x];
        }
        return x;
    }

    // 已经连通返回 false（在判环时很有用）
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (size_[rx] < size_[ry]) swap(rx, ry); // 小的挂到大的下面
        parent[ry] = rx;
        size_[rx] += size_[ry];
        --count_;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
    int  count() const { return count_; }        // 当前连通分量个数
    int  sizeOf(int x) { return size_[find(x)]; }

private:
    vector<int> parent;
    vector<int> size_;
    int count_;
};

// ------------------------------------------------------------
// 2. 冗余连接（LeetCode 684）
//    n 个点 n 条边必有且仅有一个环，
//    第一条「两端已连通」的边就是要删的那条
//    Time O(n·α(n)) / Space O(n)
// ------------------------------------------------------------
vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
    DSU dsu((int)edges.size() + 1);              // 节点编号 1..n
    for (const auto& e : edges)
        if (!dsu.unite(e[0], e[1])) return e;    // 合并失败 = 成环
    return {};
}

// ------------------------------------------------------------
// 3. 省份数量（LeetCode 547）：连通分量计数
//    Time O(n^2 · α(n)) / Space O(n)
// ------------------------------------------------------------
int findCircleNum(const vector<vector<int>>& isConnected) {
    int n = (int)isConnected.size();
    DSU dsu(n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (isConnected[i][j]) dsu.unite(i, j);
    return dsu.count();
}

// ------------------------------------------------------------
// 4. 账户合并（LeetCode 721）
//    并查集的典型用法：用 map 把「非整数元素」映射成下标
//    同一账户内的邮箱两两相连（都连到第一个邮箱即可）
//    Time O(n·L·α) + 排序 / Space O(n·L)
// ------------------------------------------------------------
vector<vector<string>> accountsMerge(const vector<vector<string>>& accounts) {
    unordered_map<string, int>    emailId;       // email -> 下标
    unordered_map<string, string> emailName;     // email -> 用户名
    for (const auto& acc : accounts)
        for (size_t i = 1; i < acc.size(); ++i)
            if (!emailId.count(acc[i])) {
                emailId[acc[i]] = (int)emailId.size();
                emailName[acc[i]] = acc[0];
            }

    DSU dsu((int)emailId.size());
    for (const auto& acc : accounts)
        for (size_t i = 2; i < acc.size(); ++i)
            dsu.unite(emailId[acc[1]], emailId[acc[i]]);

    unordered_map<int, vector<string>> groups;   // 根 -> 该组所有邮箱
    for (const auto& [mail, id] : emailId) groups[dsu.find(id)].push_back(mail);

    vector<vector<string>> res;
    for (auto& [root, mails] : groups) {
        sort(mails.begin(), mails.end());
        vector<string> one{emailName[mails[0]]};
        one.insert(one.end(), mails.begin(), mails.end());
        res.push_back(one);
    }
    return res;
}

// ------------------------------------------------------------
// 5. Kruskal：边按权值升序，不成环就选
//    选够 n-1 条边即为最小生成树
//    Time O(E log E) / Space O(V + E)
// ------------------------------------------------------------
struct Edge {
    int u, v, w;
};

int kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) { return a.w < b.w; });

    DSU dsu(n);
    int total = 0, used = 0;
    for (const auto& e : edges) {
        if (!dsu.unite(e.u, e.v)) continue;      // 会成环，跳过
        total += e.w;
        if (++used == n - 1) break;              // 边数够了，提前结束
    }
    return used == n - 1 ? total : -1;           // -1：图不连通
}

// 应用：连接所有点的最小费用（LeetCode 1584，曼哈顿距离完全图）
int minCostConnectPoints(const vector<vector<int>>& points) {
    int n = (int)points.size();
    vector<Edge> edges;
    edges.reserve((size_t)n * (n - 1) / 2);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edges.push_back({i, j,
                abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
    return kruskal(n, edges);
}

// ------------------------------------------------------------
// 6. Prim：从一个点开始，每次把「离已选集合最近的点」拉进来
//    优先队列版，适合边比较稀疏的情况
//    Time O(E log V) / Space O(V + E)
// ------------------------------------------------------------
int prim(int n, const vector<vector<pair<int, int>>>& g) {   // g[u] = {(v, w), ...}
    vector<char> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;   // (w, node)
    pq.push({0, 0});

    int total = 0, picked = 0;
    while (!pq.empty() && picked < n) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;                  // 已在树中，跳过
        inMST[u] = true;
        total += w;
        ++picked;
        for (auto& [v, wt] : g[u])
            if (!inMST[v]) pq.push({wt, v});
    }
    return picked == n ? total : -1;             // -1：图不连通
}

// 稠密图（如完全图）用 O(V^2) 的朴素 Prim 更快，不需要优先队列
int primDense(int n, const vector<vector<int>>& dist) {      // dist 为邻接矩阵
    const int INF = INT_MAX / 2;
    vector<int>  minDist(n, INF);
    vector<char> inMST(n, false);
    minDist[0] = 0;

    int total = 0;
    for (int it = 0; it < n; ++it) {
        int u = -1;
        for (int v = 0; v < n; ++v)              // 找未入树中 minDist 最小的点
            if (!inMST[v] && (u == -1 || minDist[v] < minDist[u])) u = v;
        if (minDist[u] == INF) return -1;        // 不连通

        inMST[u] = true;
        total += minDist[u];
        for (int v = 0; v < n; ++v)              // 用 u 更新其余点的接入代价
            if (!inMST[v]) minDist[v] = min(minDist[v], dist[u][v]);
    }
    return total;
}
