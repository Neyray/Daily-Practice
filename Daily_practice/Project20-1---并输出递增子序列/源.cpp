#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // 用于字符串操作

using namespace std;

pair<int, string> lengthOfLis(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return { -1, "" };

    vector<int> dp(n, 1);  // 每个元素至少能成为一个长度为1的子序列
    int maxLength = 1;     // 最长递增子序列的长度，初始为1
    int bestEnd = 0;       // 最长递增子序列的结束位置

    // 动态规划计算每个位置的最长递增子序列长度
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 更新最大长度及其结束位置
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            bestEnd = i;
        }
    }

    // 通过dp数组追踪出最长递增子序列
    vector<int> lis;
    for (int i = bestEnd; i >= 0; --i) {
        if (dp[i] == maxLength) {
            lis.push_back(nums[i]);
            maxLength--;
        }
        if (maxLength == 0) break;
    }

    reverse(lis.begin(), lis.end());  // 反转子序列，使其按顺序排列

    // 将整数数组转换为字符串
    string result = "";
    for (int num : lis) {
        result += to_string(num) + " ";
    }

    return { lis.size(), result };
}

int main() {
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };

    auto result = lengthOfLis(nums);
    cout << "最长递增子序列的长度: " << result.first << endl;
    cout << "最长递增子序列: " << result.second << endl;

    return 0;
}
