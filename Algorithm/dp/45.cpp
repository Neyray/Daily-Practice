// 跳跃游戏II
#include <iostream>
#include <vector>
using namespace std;

// 动态规划
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, n + 1);
    dp[0] = 0;

    // 由于跳跃长度可以小于nums[i]，所以采用遍历方式
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j + nums[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}