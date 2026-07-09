#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

const int INF = INT_MAX;

struct MatrixGraph {
    vector<vector<int>> matrix;
    int vertices;//元素个数
    bool isDirected;
};

void initGraph(MatrixGraph& graph, int v, bool directed = false) {
    graph.vertices = v;
    graph.isDirected = directed;
    graph.matrix.resize(v, vector<int>(v, INF));
    //初始化对角线元素
    for (int i = 0; i < v; i++)
        graph.matrix[i][i] = 0;
}

void addEdge(MatrixGraph& graph, int u, int v, int weight = 1) {
    if (u < 0 || u >= graph.vertices || v < 0 || v >= graph.vertices) return;

    graph.matrix[u][v] = weight;
    if (!graph.isDirected)
        graph.matrix[v][u] = weight;
}

void removeEdge(MatrixGraph& graph, int u, int v) {
    if (u < 0 || u >= graph.vertices || v < 0 || v >= graph.vertices) return;

    graph.matrix[u][v] = INF;
    if (!graph.isDirected)
        graph.matrix[v][u] = INF;
}

bool hasEdge(const MatrixGraph& graph, int u, int v) {
    if (u < 0 || u >= graph.vertices || v < 0 || v >= graph.vertices)
        return false;
    return graph.matrix[u][v] != INF;
}

int getWeight(const MatrixGraph& graph, int u, int v) {
    return hasEdge(graph, u, v) ? graph.matrix[u][v] : INF;
}

void printMatrix(const MatrixGraph& graph) {
    cout << "\n邻接矩阵 ("
        << (graph.isDirected ? "有向图" : "无向图") << "):\n    ";

    for (int j = 0; j < graph.vertices; j++)
        cout << setw(3) << j;
    cout << endl;

    for (int i = 0; i < graph.vertices; i++) {
        cout << setw(3) << i;
        for (int j = 0; j < graph.vertices; j++)
            cout << setw(3) << (graph.matrix[i][j] == INF ? "∞" : to_string(graph.matrix[i][j]));
        cout << endl;
    }
}

// DFS 递归工具函数
void dfsUtil(const MatrixGraph& graph, int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < graph.vertices; i++)
        if (graph.matrix[vertex][i] != INF && !visited[i])
            dfsUtil(graph, i, visited);
}

// DFS 入口函数
void dfs(const MatrixGraph& graph, int startVertex) {
    vector<bool> visited(graph.vertices, false);
    cout << "DFS 从 " << startVertex << ": ";
    dfsUtil(graph, startVertex, visited);
    cout << endl;
}

// BFS 遍历
void bfs(const MatrixGraph& graph, int startVertex) {
    vector<bool> visited(graph.vertices, false);
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    cout << "BFS 从 " << startVertex << ": ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < graph.vertices; i++)
            if (graph.matrix[current][i] != INF && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
    }
    cout << endl;
}

int getDegree(const MatrixGraph& graph, int vertex) {
    if (vertex < 0 || vertex >= graph.vertices) return -1;
    int degree = 0;
    for (int i = 0; i < graph.vertices; i++)
        if (graph.matrix[vertex][i] != INF)
            degree++;
    return degree;
}

int main() {
    // 无向图演示
    MatrixGraph ugraph;
    initGraph(ugraph, 5, false);
    addEdge(ugraph, 0, 1, 2);
    addEdge(ugraph, 0, 3, 6);
    addEdge(ugraph, 1, 2, 3);
    addEdge(ugraph, 1, 3, 8);
    addEdge(ugraph, 1, 4, 5);
    addEdge(ugraph, 2, 4, 7);

    printMatrix(ugraph);
    dfs(ugraph, 0);
    bfs(ugraph, 0);
    cout << "顶点 1 的度数: " << getDegree(ugraph, 1) << endl;

    // 有向图演示
    MatrixGraph dgraph;
    initGraph(dgraph, 4, true);
    addEdge(dgraph, 0, 1, 1);
    addEdge(dgraph, 0, 2, 1);
    addEdge(dgraph, 2, 3, 1);
    addEdge(dgraph, 3, 1, 1);

    printMatrix(dgraph);
    cout << "顶点 1 的出度: " << getDegree(dgraph, 1) << endl;
    return 0;
}