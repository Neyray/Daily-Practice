// ============================================================
// Topic : Tree / DFS / BFS / Topological Sort / Shortest Path
// Dir   : Algorithm/graph/
//
// 图论题的第一步永远是「建图」：
//   邻接表  vector<vector<pair<int,int>>> g;   // g[u] = {(v, w), ...}
//   邻接矩阵 vector<vector<int>> g;            // 点少、稠密、Floyd 时用
//
// 最短路怎么选：
//   BFS            边权全为 1          O(V + E)
//   Dijkstra       非负权，单源        O(E log V)   —— 有负权就不能用
//   Bellman-Ford   允许负权 / 限制步数  O(V·E)      —— 可判负环
//   Floyd-Warshall 全源，点少(n<=400)  O(V^3)
// ============================================================

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ------------------------------------------------------------
// 1. 二叉树递归遍历：中序（LeetCode 94）
//    前 / 中 / 后序的差别只在「处理当前节点」这一行的位置
//    Time O(n) / Space O(h)
// ------------------------------------------------------------
void inorder(TreeNode* root, vector<int>& out) {
    if (!root) return;                       // Base Case
    inorder(root->left, out);
    out.push_back(root->val);                // 中序：夹在两次递归中间
    inorder(root->right, out);
}

// 迭代版中序：显式栈模拟递归，先一路向左压栈
vector<int> inorderIterative(TreeNode* root) {
    vector<int> out;
    vector<TreeNode*> stk;
    TreeNode* cur = root;
    while (cur || !stk.empty()) {
        while (cur) { stk.push_back(cur); cur = cur->left; }
        cur = stk.back(); stk.pop_back();
        out.push_back(cur->val);
        cur = cur->right;
    }
    return out;
}

// ------------------------------------------------------------
// 2. 层序遍历（LeetCode 102）
//    进循环时先记住 queue 当前大小，这一批就是一层
//    Time O(n) / Space O(n)
// ------------------------------------------------------------
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = (int)q.size();              // 固定住本层节点数
        vector<int> level;
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

// ------------------------------------------------------------
// 3. 树的递归：最大深度（LeetCode 104）/ 最近公共祖先（LeetCode 236）
//    重点是想清楚「递归函数返回什么」
// ------------------------------------------------------------
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 返回值含义：以 root 为根的子树中，p / q 的 LCA；若只找到一个则返回那一个；都没有返回空
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left,  p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;                 // 左右各找到一个 -> 当前就是 LCA
    return l ? l : r;                        // 否则把找到的那个往上传
}

// ------------------------------------------------------------
// 4. 网格 DFS：岛屿数量（LeetCode 200）
//    「沉岛」：访问过就直接改成 '0'，省掉 visited 数组
//    Time O(m·n) / Space O(m·n)（最坏递归深度）
// ------------------------------------------------------------
void floodFill(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size()) return;
    if (grid[i][j] != '1') return;
    grid[i][j] = '0';                        // 标记已访问
    floodFill(grid, i + 1, j);
    floodFill(grid, i - 1, j);
    floodFill(grid, i, j + 1);
    floodFill(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    for (int i = 0; i < (int)grid.size(); ++i)
        for (int j = 0; j < (int)grid[0].size(); ++j)
            if (grid[i][j] == '1') { ++cnt; floodFill(grid, i, j); }
    return cnt;
}

// ------------------------------------------------------------
// 5. 多源 BFS：腐烂的橘子（LeetCode 994）
//    所有初始腐烂点一起入队作为第 0 层，层数就是分钟数
//    Time O(m·n) / Space O(m·n)
// ------------------------------------------------------------
const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int orangesRotting(vector<vector<int>>& grid) {
    int m = (int)grid.size(), n = (int)grid[0].size(), fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) q.push({i, j});       // 多源：全部入队
            else if (grid[i][j] == 1) ++fresh;
        }

    int minutes = 0;
    while (!q.empty() && fresh > 0) {
        int sz = (int)q.size();
        ++minutes;                                     // 每处理一层 = 过了一分钟
        for (int t = 0; t < sz; ++t) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d : DIR) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                --fresh;
                q.push({nx, ny});
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}

// ------------------------------------------------------------
// 6. 拓扑排序 —— Kahn / BFS 入度法（LeetCode 207 / 210）
//    入度为 0 的点入队；出队时把后继入度减 1，减到 0 再入队
//    最终出队数 < n 说明有环
//    Time O(V + E) / Space O(V + E)
// ------------------------------------------------------------
vector<int> topoSort(int n, const vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    for (const auto& p : prerequisites) {              // p = {course, prereq}
        g[p[1]].push_back(p[0]);                       // prereq -> course
        ++indeg[p[0]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : g[u]) if (--indeg[v] == 0) q.push(v);
    }
    return (int)order.size() == n ? order : vector<int>{};   // 空表示有环
}

// ------------------------------------------------------------
// 7. Dijkstra（LeetCode 743）：非负权单源最短路
//    优先队列每次取出「当前距离最小」的点，该点距离即最终值
//    出队时用 d > dist[u] 跳过过期条目（懒删除）
//    Time O(E log V) / Space O(V + E)
// ------------------------------------------------------------
vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& g, int src) {
    const int INF = INT_MAX / 2;
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;   // (dist, node)
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;                     // 过期条目
        for (auto& [v, w] : g[u])
            if (d + w < dist[v]) {                     // 松弛
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
    }
    return dist;
}

// ------------------------------------------------------------
// 8. Bellman-Ford（LeetCode 787）：允许负权，可限制边数
//    做 k+1 轮松弛 = 最多经过 k+1 条边的最短路
//    关键：每轮必须基于「上一轮的 dist 快照」，否则一轮内会走多条边
//    Time O(k·E) / Space O(V)
// ------------------------------------------------------------
int bellmanFordLimited(int n, const vector<vector<int>>& edges,
                       int src, int dst, int k) {
    const int INF = INT_MAX / 2;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int round = 0; round <= k; ++round) {
        vector<int> snapshot = dist;                   // 快照，限制每轮只走一条边
        for (const auto& e : edges) {                  // e = {u, v, w}
            if (snapshot[e[0]] == INF) continue;
            dist[e[1]] = min(dist[e[1]], snapshot[e[0]] + e[2]);
        }
    }
    return dist[dst] == INF ? -1 : dist[dst];
}

// 完整 Bellman-Ford：跑 n-1 轮，第 n 轮还能松弛说明存在负环
bool hasNegativeCycle(int n, const vector<vector<int>>& edges) {
    const int INF = INT_MAX / 2;
    vector<int> dist(n, 0);                            // 全 0 起点，检测所有负环
    for (int round = 0; round < n - 1; ++round)
        for (const auto& e : edges)
            if (dist[e[0]] != INF)
                dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
    for (const auto& e : edges)
        if (dist[e[0]] + e[2] < dist[e[1]]) return true;
    return false;
}

// ------------------------------------------------------------
// 9. Floyd-Warshall（LeetCode 1334）：全源最短路
//    dp[k][i][j] 压成二维，中转点 k 必须放在【最外层】循环
//    Time O(V^3) / Space O(V^2)
// ------------------------------------------------------------
vector<vector<int>> floyd(int n, const vector<vector<int>>& edges) {
    const int INF = INT_MAX / 2;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (const auto& e : edges) {                      // 无向图，双向赋值
        d[e[0]][e[1]] = min(d[e[0]][e[1]], e[2]);
        d[e[1]][e[0]] = min(d[e[1]][e[0]], e[2]);
    }
    for (int k = 0; k < n; ++k)                        // 中转点在最外层！
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

// ------------------------------------------------------------
// 10. Dijkstra 变形：最小体力消耗路径（LeetCode 1631）
//     把「路径长度 = 边权之和」换成「路径代价 = 边权最大值」
//     松弛式子从 d + w 变成 max(d, w)，其余结构完全不变
//     Time O(m·n·log(m·n)) / Space O(m·n)
// ------------------------------------------------------------
int minimumEffortPath(const vector<vector<int>>& heights) {
    int m = (int)heights.size(), n = (int)heights[0].size();
    vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
    effort[0][0] = 0;

    // (代价, 行, 列)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [e, x, y] = pq.top(); pq.pop();
        if (e > effort[x][y]) continue;
        if (x == m - 1 && y == n - 1) return e;
        for (auto& d : DIR) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            int ne = max(e, abs(heights[nx][ny] - heights[x][y]));   // 瓶颈路
            if (ne < effort[nx][ny]) {
                effort[nx][ny] = ne;
                pq.push({ne, nx, ny});
            }
        }
    }
    return 0;
}
