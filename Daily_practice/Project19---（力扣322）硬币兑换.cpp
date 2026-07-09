#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // dp[i] 表示凑成金额 i 所需的最少硬币数
    vector<int> dp(amount + 1, amount + 1); // 初始化为一个大于最大硬币数的数值
    dp[0] = 0; // 金额为 0 时，硬币数为 0

    // 遍历每个金额从 1 到 amount
    for (int i = 1; i <= amount; ++i) {
        // 对每一个硬币，更新 dp[i] 的值
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1); // 如果可以凑成金额 i，更新最少硬币数
            }
        }
    }

    // 如果 dp[amount] 仍然是一个很大的数，说明无法凑成该金额
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins1 = { 1, 2, 5 };
    int amount1 = 11;
    cout << "示例1的结果: " << coinChange(coins1, amount1) << endl; // 输出 3

    vector<int> coins2 = { 2 };
    int amount2 = 3;
    cout << "示例2的结果: " << coinChange(coins2, amount2) << endl; // 输出 -1

    return 0;
}
