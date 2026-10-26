// 子集II
// 有重复元素
// （1）组合问题去重：不考虑顺序，所以先对数组排序，再用(i>start && nums[i]==nums[i-1])来判断，这个式子表示之前这个数在这个位置已经被用过了
// （2）排列问题去重：考虑顺序，每次遍历i从0开始，所以需要维护标志位；同时为了方便去重，需要对数组进行排序，每次i从0开始遍历，所以无影响；
// 判断条件为(i>0 && nums[i]==nums[i-1] && !used[i-1])，表示这一轮没使用这个数，但是i是从小到大遍历，所以之前这个位置一定考虑过这个数了，所以重复
// 去重都需要进行排序
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        }
    };

    dfs(0);
    return ans;
}