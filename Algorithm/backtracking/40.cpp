// 组合总和II
// 求具体的组合，用回溯；求组合个数，用动态规划
// 搜索树中和为target的组合存入数组
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int start, int sum) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 判断的是当前数字在这一层是否为重复选择，并不禁止不同层选择相同的数值
            // 同层去重，不同层可以选择相同的值
            if (i > start && candidates[i] == candidates[i-1])
            // i > start 的作用就是：同一层中，相同数值只允许作为分支起点一次
                continue;

            // 剪枝：排序后，后面的数字只会更大
            if (sum + candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i]);
            path.pop_back();
        }
    };

    dfs(0, 0);
    return ans;
}
