#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//1.邻接矩阵
#define MAXV 100
#define INF 0x3f3f3f3f
int a[MAXV][MAXV];  // 邻接矩阵
int n, e;           // 顶点数、边数


//2.邻接表
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