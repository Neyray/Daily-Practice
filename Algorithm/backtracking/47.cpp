// 全排列II
// 包含重复数字
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used(nums.size(), false);

    function<void()> dfs = [&]() {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // 同层去重
            // 全排列一般不使用 start 限制搜索范围，而是每层遍历全部元素，通过 used 记录当前路径已经使用的位置
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            path.push_back(nums[i]);
            used[i] = true;

            dfs();

            path.pop_back();
            used[i] = false;
        }
    };

    dfs();
    return ans;
}