#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

// 边的结构体，用于AOE网
struct Edge {
    int to;     // 终点
    int weight; // 权值（活动持续时间）
    int id;     // 边的编号
};

// 全局变量
vector<vector<Edge>> graph;  // 邻接表表示图
vector<int> ve;              // 事件最早发生时间
vector<int> vl;              // 事件最迟发生时间
vector<int> indegree;        // 入度
vector<int> outdegree;       // 出度

// 拓扑排序求事件最早发生时间
bool topologicalSort(int V, vector<int>& topoOrder) {
    queue<int> q;
    topoOrder.clear();

    // 将入度为0的顶点入队
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 计算每个事件的最早发生时间
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        // 遍历u的所有邻接顶点
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // 更新最早发生时间
            ve[v] = max(ve[v], ve[u] + weight);

            // 入度减1，如果变为0则入队
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 判断是否存在环
    return topoOrder.size() == V;
}

// 逆拓扑排序求事件最迟发生时间
void reverseTopologicalSort(int V, vector<int>& topoOrder) {
    // 找到汇点（出度为0的顶点）
    int sink = -1;
    for (int i = 0; i < V; i++) {
        if (outdegree[i] == 0) {
            sink = i;
            break;
        }
    }

    // 初始化汇点的最迟发生时间
    vl[sink] = ve[sink];

    // 按拓扑排序的逆序计算最迟发生时间
    for (int i = topoOrder.size() - 2; i >= 0; i--) {
        int u = topoOrder[i];
        vl[u] = INT_MAX;

        // 遍历从u出发的所有边
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            vl[u] = min(vl[u], vl[v] - weight);
        }
    }
}

// 求关键路径
void findCriticalPath(int V) {
    vector<int> topoOrder;

    cout << "AOE网关键路径算法\n";
    cout << "================\n";

    // 1. 拓扑排序求最早发生时间
    if (!topologicalSort(V, topoOrder)) {
        cout << "图中存在环，无法求关键路径！\n";
        return;
    }

    cout << "拓扑排序结果：";
    for (int v : topoOrder) {
        cout << v << " ";
    }
    cout << "\n\n";

    // 2. 逆拓扑排序求最迟发生时间
    reverseTopologicalSort(V, topoOrder);

    // 3. 输出事件时间
    cout << "事件时间表：\n";
    cout << "事件\t最早时间(ve)\t最迟时间(vl)\t时间余量\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << ve[i] << "\t\t" << vl[i] << "\t\t" << (vl[i] - ve[i]) << "\n";
    }
    cout << "\n";

    // 4. 找出关键活动
    cout << "活动分析：\n";
    cout << "活动\t最早开始\t最迟开始\t时间余量\t是否关键\n";

    vector<pair<int, int>> criticalActivities; // 存储关键活动

    for (int u = 0; u < V; u++) {
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            int id = edge.id;

            int e = ve[u];           // 活动最早开始时间
            int l = vl[v] - weight;  // 活动最迟开始时间
            int slack = l - e;       // 时间余量

            cout << "a" << id << "(" << u << "->" << v << ")\t";
            cout << e << "\t\t" << l << "\t\t" << slack << "\t\t";

            if (slack == 0) {
                cout << "是\n";
                criticalActivities.push_back({ u, v });
            }
            else {
                cout << "否\n";
            }
        }
    }

    // 5. 输出关键路径
    cout << "\n关键活动：";
    for (int i = 0; i < criticalActivities.size(); i++) {
        if (i > 0) cout << ", ";
        cout << "(" << criticalActivities[i].first << "->" << criticalActivities[i].second << ")";
    }
    cout << "\n";

    cout << "关键路径长度：" << ve[V - 1] << "\n";
}

int main() {
    cout << "AOE网关键路径求解\n";
    cout << "================\n";

    const int V = 6; // 顶点数（事件数）

    // 初始化
    graph.resize(V);
    ve.resize(V, 0);
    vl.resize(V, 0);
    indegree.resize(V, 0);
    outdegree.resize(V, 0);

    // 构建AOE网的例子
    // 活动a0: 0->1, 权值3
    graph[0].push_back({ 1, 3, 0 });
    indegree[1]++;
    outdegree[0]++;

    // 活动a1: 0->2, 权值2
    graph[0].push_back({ 2, 2, 1 });
    indegree[2]++;
    outdegree[0]++;

    // 活动a2: 1->3, 权值2
    graph[1].push_back({ 3, 2, 2 });
    indegree[3]++;
    outdegree[1]++;

    // 活动a3: 1->4, 权值3
    graph[1].push_back({ 4, 3, 3 });
    indegree[4]++;
    outdegree[1]++;

    // 活动a4: 2->3, 权值4
    graph[2].push_back({ 3, 4, 4 });
    indegree[3]++;
    outdegree[2]++;

    // 活动a5: 2->5, 权值3
    graph[2].push_back({ 5, 3, 5 });
    indegree[5]++;
    outdegree[2]++;

    // 活动a6: 3->5, 权值2
    graph[3].push_back({ 5, 2, 6 });
    indegree[5]++;
    outdegree[3]++;

    // 活动a7: 4->5, 权值1
    graph[4].push_back({ 5, 1, 7 });
    indegree[5]++;
    outdegree[4]++;

    // 输出AOE网结构
    cout << "AOE网结构（活动弧）：\n";
    for (int u = 0; u < V; u++) {
        for (const Edge& edge : graph[u]) {
            cout << "a" << edge.id << ": " << u << " -> " << edge.to
                << " (权值: " << edge.weight << ")\n";
        }
    }
    cout << "\n";

    // 求关键路径
    findCriticalPath(V);

    return 0;
}