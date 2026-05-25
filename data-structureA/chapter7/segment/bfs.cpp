#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXV 100
#define INF 0x3f3f3f3f

//邻接表定义
struct ArcNode {        // 边结点（弧结点）
    int adjvex;         // 邻接点编号
    int weight;         // 边的权值
    ArcNode* nextarc;   // 指向下一条边
};
struct HNode {          // 头结点（顶点信息）
    string info;        // 顶点信息（可改成其他类型）
    ArcNode* firstarc;  // 指向第一条邻接边
};
class AdjGraph {
public:
    HNode adjlist[MAXV];  // 邻接表
    int n, e;             // 顶点数、边数
    
    AdjGraph() {
        for (int i = 0; i < MAXV; i++)
            adjlist[i].firstarc = NULL;
    }
    
    ~AdjGraph() {  // 释放所有边结点
        for (int i = 0; i < n; i++) {
            ArcNode* p = adjlist[i].firstarc;
            while (p != NULL) {
                ArcNode* q = p->nextarc;
                delete p;
                p = q;
            }
        }
    }

    void CreateAdjGraph(int a[][MAXV], int n, int e) {
        this->n = n; 
        this->e = e;
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >= 0; j--){     // 倒序！
                if (a[i][j] != 0 && a[i][j] != INF) {
                    ArcNode* p = new ArcNode();
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc;  // 头插
                    adjlist[i].firstarc = p;
                }
            }
        }
    }
};


//从 v 出发，先访问 v，再访问 v 的所有邻接点，再访问邻接点的邻接点……层层扩展。用队列实现。
void BFS(AdjGraph& G, int v) {
    int visited[MAXV];

    //将visited数组全部清零
    memset(visited, 0, sizeof(visited));

    queue<int> qu;
    qu.push(v);
    visited[v] = 1;//表示已经访问过了
    cout << v << " ";

    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        ArcNode* p = G.adjlist[u].firstarc;//第一条邻接边

        //当当前节点的所有邻接节点都访问完了之后，退出这个循环，再从队列弹出节点
        while (p != NULL) {
            int w = p->adjvex;
            if (visited[w] == 0) {
                cout << w << " ";
                visited[w] = 1;

                //将w放进队列，访问w的邻接节点
                qu.push(w);
            }
            p = p->nextarc;//p还是在之前开始的第一个节点的邻接节点中找
        }
    }
}