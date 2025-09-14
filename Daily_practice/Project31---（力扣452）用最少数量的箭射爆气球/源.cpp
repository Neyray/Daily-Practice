#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    // 1. 按照气球的结束坐标进行排序
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];});

    int arrowCount = 1;      // 至少需要一支箭
    int currentEnd = points[0][1];  // 当前箭的位置（初始化为第一个气球的结束坐标）

    // 2. 遍历所有气球
    for (const auto& balloon : points) {
        // 如果当前气球的开始坐标大于当前箭的位置，需要一支新的箭
        if (balloon[0] > currentEnd) {
            arrowCount++;
            currentEnd = balloon[1];  // 更新箭的位置为当前气球的结束坐标
        }
    }

    return arrowCount;
}

int main() {
    // 示例 1
    vector<vector<int>> points1 = { {10, 16}, {2, 8}, {1, 6}, {7, 12} };
    cout << "示例1的输出: " << findMinArrowShots(points1) << endl;  // 输出 2

    // 示例 2
    vector<vector<int>> points2 = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };
    cout << "示例2的输出: " << findMinArrowShots(points2) << endl;  // 输出 4

    // 示例 3
    vector<vector<int>> points3 = { {1, 2}, {2, 3}, {3, 4}, {4, 5} };
    cout << "示例3的输出: " << findMinArrowShots(points3) << endl;  // 输出 2

    return 0;
}
