//最小生成树（不得有回路）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXV = 100;            // 图中最多的顶点数
const int INF = 0x3f3f3f3f;      // 用 INF 表示 ∞

class MatGraph                 // 图邻接矩阵类
{
public:
    int edges[MAXV][MAXV];     // 邻接矩阵数组
    int n, e;                  // 顶点数、边数
    string vexs[MAXV];         // 存放顶点信息，可不用

    MatGraph()                 // 构造函数，初始化为空图
    {
        n = 0;
        e = 0;

        for (int i = 0; i < MAXV; i++)
        {
            for (int j = 0; j < MAXV; j++)
            {
                if (i == j)
                    edges[i][j] = 0;
                else
                    edges[i][j] = INF;
            }
        }
    }

    void CreateMatGraph(int a[][MAXV], int n, int e)
    // 通过邻接矩阵数组 a、顶点数 n、边数 e 建立图
    {
        this->n = n;
        this->e = e;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                this->edges[i][j] = a[i][j];
    }

    void DispMatGraph()
    // 输出图的邻接矩阵
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (edges[i][j] == INF)
                    printf("%4s", "∞");
                else
                    printf("%4d", edges[i][j]);
            }
            printf("\n");
        }
    }
};

//1.Prim算法---点优先
void Prim(MatGraph g,int v)        // Prim算法输出的最小生成树
{  
    int lowcost[MAXV];      //lowcost[j]表示该边的权值。     
    int closest[MAXV];      //closest[j]表示该最小边在U（生成树的点集合）中的顶点。j是非生成树的点（外面）

    for (int i=0;i<g.n;i++)        // 给lowcost[]和closest[]置初值
    {  
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }

    for (int i=1;i<g.n;i++)        // 找出(n-1)个顶点
    {  
        int min=INF;
        int k=-1;                  // k记录最近顶点的编号，外面的节点

        //不知道还剩几个节点，所以干脆遍历n个，在循环内部用lowcost[j]!=0来判断
        for (int j=0;j<g.n;j++)    // 在(V-U)中找出离U最近的顶点k
            if (lowcost[j]!=0 && lowcost[j]<min)
            {  
                min=lowcost[j];
                k=j;
            }

        cout << "  边(" << closest[k] << "," << k << "),权为" << min << endl;

        lowcost[k]=0;              // 标记k已经加入U

        //不知道还剩几个节点，所以干脆遍历n-1个
        for (int j=0;j<g.n;j++)    // 修改数组lowcost和closest
            if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j])//只需要对新加入的k判断
            {  
                lowcost[j]=g.edges[k][j];
                closest[j]=k;//前驱改为k
            }
    }
}


//2.Kruskal算法
struct Edge                    // 边向量元素类型
{  
    int u;                     // 边的起始顶点
    int v;                     // 边的终止顶点
    int w;                     // 边的权值

    Edge(int u,int v,int w)    // 构造函数
    {  
        this->u=u;
        this->v=v;
        this->w=w;
    }

    bool operator<(const Edge& s) const    // 重载<运算符
    {
        return w<s.w;                      // 用于按w递增排序
    }
};

void Kruskal(MatGraph& g)        // Kruskal算法输出最小生成树
{  
    int vset[MAXV];              // 建立数组vset
    vector<Edge> E;              // 建立存放所有边的向量E

    for (int i=0;i<g.n;i++)      // 由图的邻接矩阵g产生边向量E
        for (int j=0;j<g.n;j++)
            if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
                E.push_back(Edge(i,j,g.edges[i][j]));

    sort(E.begin(),E.end());     // 对E按权值递增排序

    for (int i=0;i<g.n;i++) 
        vset[i]=i;               // 初始化辅助数组

    int k=1;                     // k是当前构造生成树第几条边,初值为1
    int j=0;                     // E中边的下标,初值为0

    while (k<g.n)                // 生成的边数小于n时循环
    {  
        int u1=E[j].u;
        int v1=E[j].v;           // 取一条边的起始和终止顶点

        //判断特征位是否相同，如果相同就说明不能选
        int sn1=vset[u1];
        int sn2=vset[v1];        // 分别得到两个顶点所属的集合编号

        if (sn1!=sn2)            // 两顶点属不同集合,取该边
        {  
            cout << "  边(" << u1 << "," << v1 << "),权为" << E[j].w << endl;
            k++;                 // 生成边数增1

            //确保所有等于sn2的都换成了sn1
            for (int i=0;i<g.n;i++)    // 两个集合统一编号
                if (vset[i]==sn2)      // 集合编号为sn2的改为sn1
                    vset[i]=sn1;
        }

        j++;                     // 扫描下一条边
    }
}