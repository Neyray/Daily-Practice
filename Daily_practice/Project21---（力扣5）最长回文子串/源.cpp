#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int n = s.size();
    int start = 0, maxLength = 1;//maxLength表示长度

    // 中心扩展法
    for (int i = 0; i < n; ++i) {
        // 处理奇数长度回文
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }

        // 处理偶数长度回文
        left = i, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }
    }

    // 返回最长回文子串
    return s.substr(start, maxLength);
}

int main() {
    string s1 = "babad";
    cout << "示例1的结果: " << longestPalindrome(s1) << endl;  // 输出 "bab" 或 "aba"

    string s2 = "cbbd";
    cout << "示例2的结果: " << longestPalindrome(s2) << endl;  // 输出 "bb"

    return 0;
}
