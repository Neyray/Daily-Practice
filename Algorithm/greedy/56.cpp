// 合并区间
// 贪心：按左边界的起始位置进行排序，只需要顺序遍历一次，如果按右边界，需要回溯找最前面的位置
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (const auto& interval : intervals) {
        if (ans.empty() || ans.back()[1] < interval[0]) {
            ans.push_back(interval);
        } else {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}