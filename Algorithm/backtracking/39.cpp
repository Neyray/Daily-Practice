// 组合总和
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int start, int sum) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (sum + candidates[i] > target) break;

            path.push_back(candidates[i]);
            // 由于一个元素可以重复使用，所以不同层可以使用同一个元素
            dfs(i, sum + candidates[i]);
            path.pop_back();
        }
    };

    dfs(0, 0);
    return ans;
}