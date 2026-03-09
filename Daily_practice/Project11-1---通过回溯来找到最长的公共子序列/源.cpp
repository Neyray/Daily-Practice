#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 动态规划求解最长公共子序列长度
int longestCommonSubsequenceLength(const string& text1, const string& text2) {
    int m = text1.length();
    int n = text2.length();

    // dp[i][j]表示text1前i个字符与text2前j个字符的LCS长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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

    // 回溯找出最长公共子序列
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs = text1[i - 1] + lcs;  // 如果字符相等，则加入结果，一定要注意顺序！！！
            --i;
            --j;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;  // 向上移动
        }
        else {
            --j;  // 向左移动
        }
    }

    cout << "最长公共子序列为: " << lcs << endl;
    return dp[m][n];  // 返回最长公共子序列的长度
}

int main() {
    string text1, text2;
    cout << "请输入第一个字符串: ";
    cin >> text1;
    cout << "请输入第二个字符串: ";
    cin >> text2;

    int length = longestCommonSubsequenceLength(text1, text2);
    cout << "最长公共子序列的长度为: " << length << endl;

    return 0;
}
