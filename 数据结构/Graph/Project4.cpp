#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 找到距离最短且未访问的顶点
int minDistance(vector<int>& dist, vector<bool>& visited, int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// 打印路径
void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

// 狄克斯特拉算法求单源最短路径
void dijkstraAlgorithm(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);    // 存储最短距离
    vector<bool> visited(V, false);  // 标记是否已访问
    vector<int> parent(V, -1);       // 存储路径的父节点

    // 源点到自身的距离为0
    dist[src] = 0;

    cout << "狄克斯特拉算法求最短路径（源点：" << src << "）\n";
    cout << "========================================\n";

    // 找到所有顶点的最短路径
    for (int count = 0; count < V - 1; count++) {
        // 选择距离最短的未访问顶点
        int u = minDistance(dist, visited, V);
        visited[u] = true; // 标记为已访问

        // 更新相邻顶点的距离
        for (int v = 0; v < V; v++) {
            // 如果存在边u->v，且v未访问，且通过u到v的路径更短
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // 输出结果
    cout << "顶点\t距离\t路径\n";
    for (int i = 0; i < V; i++) {
        cout << src << " -> " << i << "\t";
        if (dist[i] == INT_MAX) {
            cout << "∞\t无路径\n";
        }
        else {
            cout << dist[i] << "\t";
            printPath(parent, i);
            cout << "\n";
        }
    }
}

// 打印邻接矩阵（用于调试）
void printGraph(vector<vector<int>>& graph, int V) {
    cout << "图的邻接矩阵表示：\n";
    cout << "   ";
    for (int i = 0; i < V; i++) cout << i << "  ";
    cout << "\n";

    for (int i = 0; i < V; i++) {
        cout << i << "  ";
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0) {
                cout << "∞  ";
            }
            else {
                cout << graph[i][j] << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cout << "狄克斯特拉算法求单源最短路径\n";
    cout << "==========================\n";

    const int V = 6; // 顶点数
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // 构建有向图的邻接矩阵
    graph[0][1] = 4;
    graph[0][2] = 2;
    graph[1][2] = 1;
    graph[1][3] = 5;
    graph[2][3] = 8;
    graph[2][4] = 10;
    graph[3][4] = 2;
    graph[3][5] = 6;
    graph[4][5] = 3;

    // 打印图的结构
    printGraph(graph, V);

    // 从顶点0开始执行狄克斯特拉算法
    dijkstraAlgorithm(graph, 0, V);

    return 0;
}