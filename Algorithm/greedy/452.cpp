// 最少射箭问题
// 贪心：按照右端点排序
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    sort(points.begin(), points.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

    int end = points[0][1];
    int count = 1;

    for (int i = 1; i < points.size(); ++i) {
        if (end < points[i][0]) {
            ++count;
            end = points[i][1];
        }
    }

    return count;
}