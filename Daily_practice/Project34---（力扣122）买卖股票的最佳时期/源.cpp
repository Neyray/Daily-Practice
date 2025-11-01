#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int profit = 0;

    // 遍历数组，累加所有价格上升的利润
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];  // 获得利润
        }
    }

    return profit;
}

int main() {
    // 示例 1
    vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
    cout << "示例1的最大利润: " << maxProfit(prices1) << endl;  // 输出 7

    // 示例 2
    vector<int> prices2 = { 1, 2, 3, 4, 5 };
    cout << "示例2的最大利润: " << maxProfit(prices2) << endl;  // 输出 4

    return 0;
}
