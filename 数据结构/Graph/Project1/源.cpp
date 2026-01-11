#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct EdgeNode {
    int adjVertex;      // 相邻顶点索引
    int weight;         // 边权重
    EdgeNode* next;     // 指向下一个边节点

    EdgeNode(int v, int w) : adjVertex(v), weight(w), next(nullptr) {}
};

struct Graph {
    vector<EdgeNode*> adjList;  // 邻接表
    int vertices;               // 顶点数
    bool directed;              // 是否是有向图
};

// 初始化图
void initGraph(Graph& g, int v, bool dir = false) {
    g.vertices = v;
    g.directed = dir;
    g.adjList.resize(v, nullptr);
}

// 添加边
void addEdge(Graph& g, int u, int v, int w = 1) {
    if (u < 0 || u >= g.vertices || v < 0 || v >= g.vertices) return;

    // 创建新边节点并插入到链表头部
    EdgeNode* newNode = new EdgeNode(v, w);
    newNode->next = g.adjList[u];//这个表示头结点
    g.adjList[u] = newNode;

    // 如果是无向图，添加反向边
    if (!g.directed) {
        EdgeNode* reverseNode = new EdgeNode(u, w);
        reverseNode->next = g.adjList[v];
        g.adjList[v] = reverseNode;
    }
}

// 打印邻接表
void printGraph(Graph& g) {
    cout << "邻接表：" << endl;
    for (int i = 0; i < g.vertices; i++) {
        cout << i << ": ";
        EdgeNode* cur = g.adjList[i];
        while (cur) {
            cout << "-> [" << cur->adjVertex << "(" << cur->weight << ")]";
            cur = cur->next;
        }
        cout << endl;
    }
}

// 深度优先遍历
void DFS(Graph& g, int start, vector<bool>& visited) {
    visited[start] = true;
    cout << start << " ";

    EdgeNode* cur = g.adjList[start];
    while (cur) {
        if (!visited[cur->adjVertex]) {
            DFS(g, cur->adjVertex, visited);
        }
        cur = cur->next;
    }
}

// 广度优先遍历
void BFS(Graph& g, int start) {
    vector<bool> visited(g.vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        EdgeNode* cur = g.adjList[u];
        while (cur) {
            if (!visited[cur->adjVertex]) {
                visited[cur->adjVertex] = true;
                q.push(cur->adjVertex);
            }
            cur = cur->next;
        }
    }
}

// 释放内存
void clearGraph(Graph& g) {
    for (int i = 0; i < g.vertices; i++) {
        EdgeNode* cur = g.adjList[i];
        while (cur) {
            EdgeNode* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
}

int main() {
    Graph g;
    initGraph(g, 5);  // 5个顶点的无向图

    // 添加边
    addEdge(g, 0, 1, 2);
    addEdge(g, 0, 3, 6);
    addEdge(g, 1, 2, 3);
    addEdge(g, 1, 4, 5);
    addEdge(g, 2, 4, 7);

    printGraph(g);

    cout << "\nDFS遍历: ";
    vector<bool> visited(g.vertices, false);
    DFS(g, 0, visited);

    cout << "\nBFS遍历: ";
    BFS(g, 0);

    clearGraph(g);
    return 0;
}