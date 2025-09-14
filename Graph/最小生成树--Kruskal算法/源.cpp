#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 边的结构体
struct Edge {
    int src, dest, weight;

    // 重载比较运算符，用于排序
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 并查集的父节点数组和秩数组
vector<int> parent, rank_arr;

// 查找根节点（带路径压缩）
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}

// 合并两个集合
bool unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        return false; // 已在同一集合中，会形成环
    }

    // 按秩合并
    if (rank_arr[rootX] < rank_arr[rootY]) {
        parent[rootX] = rootY;
    }
    else if (rank_arr[rootX] > rank_arr[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        rank_arr[rootX]++;
    }
    return true;
}

// 初始化并查集
void initUnionFind(int n) {
    parent.resize(n);
    rank_arr.resize(n, 0);
    // 初始化，每个节点的父节点是自己
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 克鲁斯卡尔算法求最小生成树
void kruskalMST(vector<Edge>& edges, int V) {
    // 1. 按权值对所有边进行排序
    sort(edges.begin(), edges.end());

    // 2. 初始化并查集
    initUnionFind(V);

    vector<Edge> mst; // 存储最小生成树的边
    int totalWeight = 0;

    cout << "克鲁斯卡尔算法求最小生成树：\n";
    cout << "按权值排序的边：\n";
    for (const Edge& e : edges) {
        cout << e.src << "-" << e.dest << "(" << e.weight << ") ";
    }
    cout << "\n\n选择的边：\n";

    // 3. 遍历排序后的边
    for (const Edge& edge : edges) {
        // 如果加入该边不会形成环
        if (unionSets(edge.src, edge.dest)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            cout << edge.src << " - " << edge.dest << " \t权值: " << edge.weight << "\n";

            // MST包含V-1条边即可停止
            if (mst.size() == V - 1) {
                break;
            }
        }
    }

    cout << "\n最小生成树总权值：" << totalWeight << endl;
}

int main() {
    cout << "克鲁斯卡尔算法求最小生成树\n";
    cout << "========================\n";

    const int V = 5; // 顶点数
    vector<Edge> edges;

    // 添加边（顶点编号从0开始）
    edges.push_back({ 0, 1, 2 });
    edges.push_back({ 0, 3, 6 });
    edges.push_back({ 1, 2, 3 });
    edges.push_back({ 1, 3, 8 });
    edges.push_back({ 1, 4, 5 });
    edges.push_back({ 2, 4, 7 });
    edges.push_back({ 3, 4, 9 });

    // 执行克鲁斯卡尔算法
    kruskalMST(edges, V);

    return 0;
}