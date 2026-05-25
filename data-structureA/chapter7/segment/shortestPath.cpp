//最短路径
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

//1.Dijkstra算法，单源
void DispAllPath(int dist[],int path[],int S[],int v,int n)
// 输出从顶点v出发的所有最短路径
{  
    for (int i=0;i<n;i++)           // 循环输出从顶点v到i的路径
    // i 是当前要输出路径的终点
        if (S[i]==1 && i!=v)
        {  
            vector<int> apath;      // 存放一条最短逆路径

            printf("  从%d到%d最短路径长度为: %d\t路径: ",v,i,dist[i]);

            //apath一开始就是终点
            apath.push_back(i);     // 添加终点i
            int pre=path[i];

            while (pre!=v)
            {  
                apath.push_back(pre);
                pre=path[pre];
            }

            printf("%d",v);         // 先输出起点v

            for (int k=apath.size()-1;k>=0;k--)    
                printf("->%d",apath[k]);   // 再反向输出路径中其他顶点

            printf("\n");
        }
        else 
            printf("  从%d到%d没有路径\n",v,i);
}

void Dijkstra(MatGraph& g,int v)    // 求从v到其他顶点的最短路径
{  
    int dist[MAXV];                 // 保存最短路径长度
    int path[MAXV];                 // 保存最短路径，其中path[i]存放从源点v到顶点i的最短路径(这条路径上i的前驱)
    int S[MAXV];                    // 判断顶点i属于哪个集合

    for (int i=0;i<g.n;i++)
    {  
        dist[i]=g.edges[v][i];      // 距离初始化
        S[i]=0;                     // S[]置空

        if (g.edges[v][i]!=0 && g.edges[v][i]<INF)
            path[i]=v;              // v到i有边时，置i的前驱顶点为v
        else
            path[i]=-1;             // v到i没边时，置i的前驱顶点为-1
    }

    S[v]=1;                         // 源点编号v放入S中

    int mindis,u=-1;

    for (int i=0;i<g.n-1;i++)       // 循环向S中添加n-1个顶点
    {  
        mindis=INF;                 // mindis置最小距离初值

        for (int j=0;j<g.n;j++)     // 选取不在S中（S[j]==0）且具有最小距离的顶点u
            if (S[j]==0 && dist[j]<mindis) //mindus设为INF表示一定有最小距离
            {  //不在S中+离v节点最近
                u=j;
                mindis=dist[j];
            }

        S[u]=1;                     // 顶点u加入S中

        //同样地，对n-1个节点遍历，在循环内判断
        for (int j=0;j<g.n;j++)     // 修改不在S中的顶点的距离
            if (S[j]==0)
                if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
                {  //对新加入的节点u进行判断
                    //如果外面有节点和u有边+通过u节点的路径比原来更短
                    dist[j]=dist[u]+g.edges[u][j];
                    path[j]=u;
                }
    }

    DispAllPath(dist,path,S,v,g.n); // 输出所有最短路径及长度
}

//2.Floyd算法
void Dispath(int A[][MAXV],int path[][MAXV],int n)
// 输出所有的最短路径和长度
{  
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {  
            if (A[i][j]!=INF && i!=j)    // 若顶点i和j之间存在路径
            {  
                vector<int> apath;       // 存放一条i到j的最短逆路径

                printf("顶点%d到%d的最短路径长度:%d\t路径:",i,j,A[i][j]);

                apath.push_back(j);      // 路径上添加终点j
                int pre=path[i][j];

                while (pre!=i)           // 路径上添加中间点
                {  
                    apath.push_back(pre); // 顶点pre加入到路径中
                    pre=path[i][pre];
                }

                cout << i;               // 输出起点i

                for (int k=apath.size()-1;k>=0;k--)
                    printf("->%d",apath[k]);  // 反向输出路径上的其他顶点

                printf("\n");
            }
        }
}

void Floyd(MatGraph& g)             // Floyd求多源最短路径
{  
    int A[MAXV][MAXV];              // 建立A数组
    int path[MAXV][MAXV];           // 建立path数组

    for (int i=0;i<g.n;i++)         // 给数组A和path置初值
        for (int j=0;j<g.n;j++) 
        {  
            A[i][j]=g.edges[i][j];

            if (i!=j && g.edges[i][j]<INF)
                path[i][j]=i;       // i和j顶点之间有一条边时
            else    
                path[i][j]=-1;      // i和j顶点之间没有一条边时
        }

    for (int k=0;k<g.n;k++)         // 求Ak[i][j]    // k 代表尝试引入的中间过渡顶点
    {  
        for (int i=0;i<g.n;i++)// i 为源点
            for (int j=0;j<g.n;j++)// j 为终点
                if (A[i][j]>A[i][k]+A[k][j])// 如果绕道 k 点比直接走更短
                {  
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=path[k][j];    // 修改最短路径
                }
    }

    Dispath(A,path,g.n);            // 输出最短路径和长度
}
