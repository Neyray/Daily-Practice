#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    // dp[i]表示s[0..i-1]是否可以由字典中的单词拼接得到
    vector<bool> dp(n + 1, false);
    dp[0] = true; // 空字符串是可以拼接得到的

    // 遍历字符串s的每个位置
    for (int i = 1; i <= n; ++i) {
        // 检查从i位置往回扫描的子串
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n]; // 返回s[0..n-1]是否可以拼接
}

int main() {
    // 示例1
    string s1 = "leetcode";
    vector<string> wordDict1 = { "leet", "code" };
    cout << "示例1的结果: " << (wordBreak(s1, wordDict1) ? "true" : "false") << endl;

    // 示例2
    string s2 = "applepenapple";
    vector<string> wordDict2 = { "apple", "pen" };
    cout << "示例2的结果: " << (wordBreak(s2, wordDict2) ? "true" : "false") << endl;

    // 示例3
    string s3 = "catsandog";
    vector<string> wordDict3 = { "cats", "dog", "sand", "and", "cat" };
    cout << "示例3的结果: " << (wordBreak(s3, wordDict3) ? "true" : "false") << endl;

    return 0;
}
