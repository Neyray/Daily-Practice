#include <iostream>
#include <vector>
using namespace std;

// 动态规划解法
int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "请输入楼梯的阶数: ";
    cin >> n;
    cout << "爬到楼顶的方法数: " << climbStairs(n) << endl;

    return 0;

}
