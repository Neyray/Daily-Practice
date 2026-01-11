#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 找到权值最小且未包含在MST中的顶点
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// 普利姆算法求最小生成树
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V); // 存储MST的父节点
    vector<int> key(V);    // 存储到MST的最小权值
    vector<bool> mstSet(V, false); // 标记顶点是否已包含在MST中

    // 初始化所有权值为无穷大
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
    }

    // 从顶点0开始
    key[0] = 0;
    parent[0] = -1; // 根节点

    // MST包含V-1条边
    for (int count = 0; count < V - 1; count++) {
        // 选择权值最小的顶点
        int u = minKey(key, mstSet, V);
        mstSet[u] = true; // 将该顶点加入MST

        // 更新相邻顶点的权值
        for (int v = 0; v < V; v++) {
            // 如果存在边u-v，且v不在MST中，且权值更小
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 输出MST
    cout << "普利姆算法求得的最小生成树：\n";
    cout << "边 \t权值\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "最小生成树总权值：" << totalWeight << endl;
}

int main() {
    cout << "普利姆算法求最小生成树\n";
    cout << "====================\n";

    const int V = 5; // 顶点数
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // 构建邻接矩阵（无向图）
    graph[0][1] = graph[1][0] = 2;
    graph[0][3] = graph[3][0] = 6;
    graph[1][2] = graph[2][1] = 3;
    graph[1][3] = graph[3][1] = 8;
    graph[1][4] = graph[4][1] = 5;
    graph[2][4] = graph[4][2] = 7;
    graph[3][4] = graph[4][3] = 9;

    // 执行普利姆算法
    primMST(graph, V);

    return 0;
}