// 子集
// 元素互不相同
// 搜索树的每一个节点都是子集
#include <iostream>
#include <vector>
#include <functional>
using namespace std;


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int start) {
        // 每个节点都是一个合法子集
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]); // 选择

            dfs(i + 1);              // 递归

            path.pop_back();         // 回溯
        }
    };

    dfs(0);
    return ans;
}
