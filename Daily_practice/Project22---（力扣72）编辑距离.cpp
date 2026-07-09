#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    // 创建一个 (m+1) x (n+1) 的 dp 数组
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 初始化 dp 数组
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // 将 word1[0..i-1] 转换为空字符串需要 i 次删除操作
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // 将空字符串转换为 word2[0..j-1] 需要 j 次插入操作
    }

    // 填充 dp 数组
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // 如果字符相等，不需要操作
            }
            else {
                //实现三个数的大小比较！！！
                dp[i][j] = min({ dp[i - 1][j] + 1,  // 删除操作
                                dp[i][j - 1] + 1,  // 插入操作
                                dp[i - 1][j - 1] + 1 });  // 替换操作
            }
        }
    }

    return dp[m][n];  // 返回将 word1 转换为 word2 所需的最少操作数
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << "示例1的结果: " << minDistance(word1, word2) << endl;  // 输出 3

    string word3 = "intention";
    string word4 = "execution";
    cout << "示例2的结果: " << minDistance(word3, word4) << endl;  // 输出 5

    return 0;
}
