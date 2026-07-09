#include <vector>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();    // 行数
    int n = obstacleGrid[0].size(); // 列数

    // 如果起点或者终点有障碍物，直接返回0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
        return 0;
    }

    // dp 数组表示到达每个位置的路径数量
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 起点位置的路径数量设为1
    dp[0][0] = 1;

    // 填充 dp 数组
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) { // 如果当前位置有障碍物，跳过
                dp[i][j] = 0;
            }
            else {
                if (i > 0) dp[i][j] += dp[i - 1][j];  // 从上方来
                if (j > 0) dp[i][j] += dp[i][j - 1];  // 从左方来
            }
        }
    }

    // 右下角的路径数就是我们要返回的答案
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> obstacleGrid1 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    vector<vector<int>> obstacleGrid2 = { {0, 1}, {0, 0} };

    cout << "Example 1: " << uniquePathsWithObstacles(obstacleGrid1) << endl; // 输出 2
    cout << "Example 2: " << uniquePathsWithObstacles(obstacleGrid2) << endl; // 输出 1

    return 0;
}
