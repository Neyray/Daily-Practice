// 组合总和IV
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int combinationSum4(vector<int>& nums, int target) {
    // 完全背包问题
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // 顺序不同序列不同，所以先遍历target
    for (int i = 1; i <= target; ++i) {
        for (int num : nums) {
            if (i >= num) {
                if (dp[i] > INT_MAX - dp[i - num]) {
                    dp[i] = INT_MAX;
                } else {
                    dp[i] += dp[i - num];
                }
            }
        }
    }
    return dp[target];
}
