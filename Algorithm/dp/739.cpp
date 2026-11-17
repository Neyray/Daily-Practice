// 每日温度
// 动态规划，从后往前
#include <iostream>
#include <vector>
using namespace std;


vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; --i) {
        int j = i + 1;

        // 右边的温度不高于当前温度
        while (j < n && temperatures[j] <= temperatures[i]) {

            // j 后面没有更高温度，直接结束
            if (dp[j] == 0) {
                j = n;
                break;
            }

            // 利用已经计算好的答案跳跃
            j += dp[j];
        }

        if (j < n) {
            dp[i] = j - i;
        }
    }

    return dp;
}
