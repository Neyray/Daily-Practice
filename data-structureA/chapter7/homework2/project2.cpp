//Floyd算法求最小环
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 105;

int n, m;
int g[MAXN][MAXN];      // 原图边权
int dista[MAXN][MAXN];  // Floyd 最短路数组

int main() {
    while (cin >> n >> m) {
        // 初始化
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    g[i][j] = dista[i][j] = 0;
                }
                else {
                    g[i][j] = dista[i][j] = INF;
                }
            }
        }

        // 读入无向图
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;

            // 可能有重边，保留最小边
            if (c < g[a][b]) {
                g[a][b] = g[b][a] = c;
                dista[a][b] = dista[b][a] = c;
            }
        }

        int ans = INF;

        // Floyd 求最小环
        for (int k = 1; k <= n; ++k) {

            // 在用 k 更新最短路之前，先尝试找经过 k 的最小环
            for (int i = 1; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    if (dista[i][j] != INF && g[i][k] != INF && g[k][j] != INF) {
                        ans = min(ans, dista[i][j] + g[i][k] + g[k][j]);
                    }
                }
            }

            // 正常 Floyd 更新
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dista[i][k] != INF && dista[k][j] != INF) {
                        dista[i][j] = min(dista[i][j], dista[i][k] + dista[k][j]);
                    }
                }
            }
        }

        if (ans == INF) {
            cout << "It's impossible." << endl;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}