#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2; // 使用较小的无穷大值，避免溢出

// 打印距离矩阵
void printMatrix(vector<vector<int>>& dist, int V) {
    cout << "最短距离矩阵：\n";
    cout << "    ";
    for (int i = 0; i < V; i++) cout << i << "   ";
    cout << "\n";

    for (int i = 0; i < V; i++) {
        cout << i << "   ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "∞   ";
            }
            else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// 打印路径
void printPath(vector<vector<int>>& path, int i, int j) {
    if (path[i][j] == -1) {
        cout << i << " -> " << j;
        return;
    }
    printPath(path, i, path[i][j]);
    cout << " -> " << j;
}

// 弗洛伊德算法求全源最短路径
void floydWarshall(vector<vector<int>>& graph, int V) {
    // 初始化距离矩阵和路径矩阵
    vector<vector<int>> dist(V, vector<int>(V));
    vector<vector<int>> path(V, vector<int>(V, -1)); // 存储路径信息

    // 初始化距离矩阵
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0; // 自己到自己距离为0
            }
            else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j]; // 直接相连的边
            }
            else {
                dist[i][j] = INF; // 不相连设为无穷大
            }
        }
    }

    cout << "弗洛伊德算法求全源最短路径\n";
    cout << "========================\n";
    cout << "初始距离矩阵：\n";
    printMatrix(dist, V);

    // 弗洛伊德算法核心：三重循环
    for (int k = 0; k < V; k++) {
        cout << "经过中间顶点 " << k << " 后的距离矩阵：\n";

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // 如果通过顶点k的路径更短，则更新
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k; // 记录中间顶点
                }
            }
        }

        printMatrix(dist, V);
    }

    // 输出最终结果
    cout << "最终最短路径结果：\n";
    cout << "起点\t终点\t距离\t路径\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                cout << i << "\t" << j << "\t";
                if (dist[i][j] == INF) {
                    cout << "∞\t无路径\n";
                }
                else {
                    cout << dist[i][j] << "\t";
                    printPath(path, i, j);
                    cout << "\n";
                }
            }
        }
    }

    // 检测负环
    bool hasNegativeCycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\n警告：图中存在负环！\n";
    }
    else {
        cout << "\n图中不存在负环。\n";
    }
}

int main() {
    cout << "弗洛伊德算法求全源最短路径\n";
    cout << "==========================\n";

    const int V = 4; // 顶点数
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // 构建有向图的邻接矩阵
    graph[0][1] = 3;
    graph[0][2] = 8;
    graph[0][3] = INF; // 使用INF表示不相连
    graph[1][0] = INF;
    graph[1][2] = INF;
    graph[1][3] = 1;
    graph[2][0] = INF;
    graph[2][1] = 4;
    graph[2][3] = INF;
    graph[3][0] = 2;
    graph[3][1] = INF;
    graph[3][2] = -5;

    cout << "输入图的邻接矩阵：\n";
    cout << "    ";
    for (int i = 0; i < V; i++) cout << i << "   ";
    cout << "\n";

    for (int i = 0; i < V; i++) {
        cout << i << "   ";
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF) {
                cout << "∞   ";
            }
            else {
                cout << graph[i][j] << "   ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    // 执行弗洛伊德算法
    floydWarshall(graph, V);

    return 0;
}