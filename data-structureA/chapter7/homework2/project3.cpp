#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ifstream inFile("in.txt");
    int n;

    // 多组输入，n == 0 时结束
    while (inFile >> n && n != 0) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

        // 自己到自己距离为 0
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
        }

        // 读入每个经纪人的联系人信息
        for (int i = 1; i <= n; ++i) {
            int m;
            inFile >> m;

            for (int j = 0; j < m; ++j) {
                int v, w;
                inFile >> v >> w;

                // i 可以把消息传给 v，花费 w 分钟
                dist[i][v] = w;
            }
        }

        // Floyd 算法：求任意两点之间的最短路径
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int bestPerson = -1;
        int bestTime = INF;

        // 枚举每个人作为消息起点
        for (int i = 1; i <= n; ++i) {
            int maxTime = 0;
            bool canReachAll = true;

            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] == INF) {
                    canReachAll = false;
                    break;//退出小循环
                }

                maxTime = max(maxTime, dist[i][j]);//最大的时间就是从起点到终点的时间
            }

            // 如果 i 能传到所有人，并且所需总时间更短
            if (canReachAll && maxTime < bestTime) {
                bestTime = maxTime;
                bestPerson = i;
            }
        }

        if (bestPerson == -1) {
            cout << "disjoint" << endl;
        } else {
            cout << bestPerson << " " << bestTime << endl;
        }
    }

    return 0;
}