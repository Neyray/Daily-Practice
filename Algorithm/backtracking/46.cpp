// 全排列
// 数字全不一样
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    // 维护一个标志位，判断是否访问

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