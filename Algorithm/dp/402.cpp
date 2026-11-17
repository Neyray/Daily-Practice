// 移掉k位数字
// 删掉左边的山峰
// 动态规划思想，实则应该使用单调栈
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    while (k > 0) {
        int n = num.size();

        // dp[i]：左边最近的、更大的数字的下标
        vector<int> dp(n, -1);

        for (int i = 1; i < n; ++i) {
            int j = i - 1;

            // 跳过所有不大于当前数字的元素
            while (j != -1 && num[j] <= num[i]) {
                j = dp[j];
            }

            dp[i] = j;
        }

        // 默认删除最后一个数字
        int pos = n - 1;

        for (int i = 1; i < n; ++i) {
            if (dp[i] != -1) {
                pos = i - 1;
                break;
            }
        }

        // 删除选中的数字
        num.erase(pos, 1);
        k--;
    }

    // 去除前导零
    int i = 0;
    while (i < num.size() && num[i] == '0') {
        i++;
    }

    string ans = num.substr(i);
    return ans.empty() ? "0" : ans;
}
