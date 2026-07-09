//寻找公共祖先
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 打开输入文件
    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "error!";
        return -1;
    }

    // 读取树的节点总数
    int n;
    inFile >> n;

    // parent数组：parent[i]表示节点i的直接父节点，初始化为0
    vector<int> parent(n + 1, 0);
    // children数组：children[p]存储节点p的所有直接子节点
    vector<vector<int>> children(n + 1);

    // 读取n-1条边构建树
    for (int i = 0; i < n - 1; ++i) {
        int p, c;
        inFile >> p >> c;  // 从文件中读取父节点p和子节点c
        parent[c] = p;     // 记录子节点c的父节点为p
        children[p].push_back(c);  // 将c添加到p的子节点列表中
    }

    // 查找根节点（唯一没有父节点的节点）
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == 0) {
            root = i;  // 找到根节点
            break;
        }
    }

    // BFS计算每个节点的深度
    vector<int> depth(n + 1, 0);  // depth[i]存储节点i的深度（根深度为0）
    queue<int> q;
    q.push(root);        // 从根节点开始遍历
    depth[root] = 0;     // 根节点深度为0

    while (!q.empty()) {
        int u = q.front();  // 取出队列头部节点u
        q.pop();
        for (int v : children[u]) {  // 遍历u的所有子节点v
            depth[v] = depth[u] + 1; // 子节点深度 = 父节点深度 + 1
            q.push(v);               // 将子节点加入队列继续遍历
        }
    }

    // 读取需要查询的两个节点u和v
    int u, v;
    inFile >> u >> v;

    // 调整u和v到同一深度
    while (depth[u] > depth[v]) {  // 如果u更深，向上移动到父节点
        u = parent[u];
    }
    while (depth[v] > depth[u]) {  // 如果v更深，向上移动到父节点
        v = parent[v];
    }

    // 同时向上移动u和v，直到找到公共祖先
    while (u != v) {     // 当u和v不相同时，继续向上移动
        u = parent[u];   // u移动到其父节点
        v = parent[v];   // v移动到其父节点
    }

    cout << u << endl;  // 输出最近公共祖先的编号

    return 0;
}
