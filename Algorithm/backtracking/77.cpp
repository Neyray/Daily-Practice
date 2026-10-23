// 组合
// 搜索树深度为k的元素组合存入结果数组
#include <iostream>
#include <vector>
#include <functional>
using namespace std;


vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int)> dfs = [&](int start) {
        // 1. 终止条件
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        // 2. 遍历当前所有可能的选择
        // push → 完整执行递归调用 → 递归返回 → pop → for 循环 i++
        for (int i = start; i <= n; ++i) {

            // 重点：递归进入下一层时，上一层会暂停在 dfs(i+1) 那里，直到下一层返回
            path.push_back(i);  // 做选择

            dfs(i + 1);         // 递归搜索

            path.pop_back();    // 撤销选择
        }
    };

    dfs(1);
    return ans;
}
