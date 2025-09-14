#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int n = prices.size();
    vector<int> hold(n, 0), cooldown(n, 0), unfrozen(n, 0);

    /*持有股票（hold）: 表示当前持有股票。
不持有股票且不在冷冻期（cooldown）: 表示当前不持有股票，并且处于冷冻期。
不持有股票且不在冷冻期的下一天（unfrozen）: 表示当前不持有股票，并且前一天不处于冷冻期。*/

    // 初始状态
    hold[0] = -prices[0];
    cooldown[0] = 0;
    unfrozen[0] = 0;

    for (int i = 1; i < n; ++i) {
        hold[i] = max(hold[i - 1], unfrozen[i - 1] - prices[i]);
        cooldown[i] = hold[i - 1] + prices[i];
        unfrozen[i] = max(unfrozen[i - 1], cooldown[i - 1]);
    }

    // 最终的最大利润在不持有股票的状态中
    return max(cooldown[n - 1], unfrozen[n - 1]);
}

int main() {
    // 示例1
    vector<int> prices1 = { 1, 2, 3, 0, 2 };
    cout << "示例1的结果: " << maxProfit(prices1) << endl;

    // 示例2
    vector<int> prices2 = { 1 };
    cout << "示例2的结果: " << maxProfit(prices2) << endl;

    return 0;
}
