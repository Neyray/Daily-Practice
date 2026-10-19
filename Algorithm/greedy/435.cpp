// 无重叠区间
// 贪心：我们希望尽可能多地保留区间，因此应该优先保留右端点更小的区间，右端点越小，意味着越早结束，给后面的区间留下的空间就越大
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

    int count = 0;
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= end) {
            end = intervals[i][1];
        } else {
            ++count;
        }
    }

    return count;
}