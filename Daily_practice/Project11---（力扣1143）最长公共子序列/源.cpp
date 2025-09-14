#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    // 创建一个 (m+1) x (n+1) 的二维数组 dp，初始值为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 填充 dp 表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // dp[m][n] 就是 text1 和 text2 的最长公共子序列的长度
    return dp[m][n];
}

int main() {
    string text1, text2;

    // 示例输入
    text1 = "abcde";
    text2 = "ace";
    cout << "输入: text1 = " << text1 << ", text2 = " << text2 << endl;
    cout << "输出: " << longestCommonSubsequence(text1, text2) << endl; // 输出 3

    text1 = "abc";
    text2 = "abc";
    cout << "输入: text1 = " << text1 << ", text2 = " << text2 << endl;
    cout << "输出: " << longestCommonSubsequence(text1, text2) << endl; // 输出 3

    text1 = "abc";
    text2 = "def";
    cout << "输入: text1 = " << text1 << ", text2 = " << text2 << endl;
    cout << "输出: " << longestCommonSubsequence(text1, text2) << endl; // 输出 0

    return 0;
}
