// 使用最小花费爬楼梯
#include <iostream>
#include <vector>
using namespace std;


int minCostClimbingStairs(vector<int>& cost) {
    int target = cost.size();

    // dp[i] = 到达第 i 级台阶所需要的最小费用
    vector<int> dp(target + 1, 0);


    // 可以从第0或第1级台阶开始爬
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= target; ++i) {
        dp[i] = min(dp[i-2] + cost[i-2],
                    dp[i-1] + cost[i-1]);
    }
    return dp[target];
}
