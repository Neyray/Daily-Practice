#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // 1. 按照区间的结束时间进行排序
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 0;          // 记录移除的区间数
    int prevEnd = intervals[0][1];  // 当前选择的区间的结束时间

    // 2. 从第二个区间开始遍历
    for (int i = 1; i < intervals.size(); ++i) {
        // 如果当前区间的开始时间小于上一个区间的结束时间，说明有重叠
        if (intervals[i][0] < prevEnd) {
            // 需要移除当前区间
            count++;
        }
        else {
            // 如果没有重叠，则选择当前区间，并更新结束时间
            prevEnd = intervals[i][1];
        }
    }

    return count;
}

int main() {
    // 示例 1
    vector<vector<int>> intervals1 = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
    cout << "示例1的输出: " << eraseOverlapIntervals(intervals1) << endl;  // 输出 1

    // 示例 2
    vector<vector<int>> intervals2 = { {1, 2}, {1, 2}, {1, 2} };
    cout << "示例2的输出: " << eraseOverlapIntervals(intervals2) << endl;  // 输出 2

    // 示例 3
    vector<vector<int>> intervals3 = { {1, 2}, {2, 3} };
    cout << "示例3的输出: " << eraseOverlapIntervals(intervals3) << endl;  // 输出 0

    return 0;
}
