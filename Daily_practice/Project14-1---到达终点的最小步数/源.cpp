#include <iostream>
#include <vector>
#include <queue>
#include <utility> // 用于pair

using namespace std;

// 定义方向数组，用于表示移动的四个方向（上、下、左、右）
int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// BFS函数，用于计算最短步数
int shortestPath(vector<vector<int>>& grid, int rows, int cols) {
    // 如果起点或终点是障碍物，则直接返回-1
    if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
        return -1;
    }

    // 创建一个队列，用于BFS
    queue<pair<int, int>> q;
    // 起点入队，并将其标记为访问过
    q.push({ 0, 0 });
    grid[0][0] = 1; // 标记为已访问

    int steps = 0; // 记录步数

    while (!q.empty()) {
        int size = q.size(); // 获取当前队列的大小

        // 遍历当前队列中的每一个节点
        for (int i = 0; i < size; ++i) {
            // 取出队列的前端元素，解包为currentRow和currentCol
            pair<int, int> current = q.front();
            q.pop();
            int currentRow = current.first;  // 当前行
            int currentCol = current.second; // 当前列

            // 如果到达终点，则返回步数
            if (currentRow == rows - 1 && currentCol == cols - 1) {
                return steps;
            }

            // 遍历四个方向
            for (auto& direction : directions) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];

                // 检查新位置是否在网格范围内且没有被访问过
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 0) {
                    q.push({ newRow, newCol }); // 将新位置加入队列
                    grid[newRow][newCol] = 1;   // 标记为已访问
                }
            }
        }
        ++steps; // 每一层迭代结束，步数加1
    }

    return -1; // 如果没有路径到达终点，返回-1
}

int main() {
    // 输入二维数组，0表示通路，1表示障碍物
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int rows = grid.size(); // 获取行数
    int cols = grid[0].size(); // 获取列数

    // 调用函数计算最短步数
    int result = shortestPath(grid, rows, cols);

    // 输出结果
    if (result != -1) {
        cout << "最短步数: " << result << endl;
    }
    else {
        cout << "没有路径可以到达终点" << endl;
    }

    return 0;
}
