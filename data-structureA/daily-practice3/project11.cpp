#include <stdio.h>

#define MAXN 205
#define INF 1000000000

int dist[MAXN][MAXN];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化距离矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // 输入边
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        // 有向边：u -> v
        // 如果有重边，保留权值更小的边
        if (w < dist[u][v]) {
            dist[u][v] = w;
        }
    }

    // Floyd算法
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // 输出结果矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                printf("INF");
            } else {
                printf("%d", dist[i][j]);
            }

            if (j != n) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
