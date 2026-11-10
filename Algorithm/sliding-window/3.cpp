// 无重复字符的最长子串
// 找最长：不满足条件右移left，一旦满足就停止移动，保证长度尽可能大
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();

    vector<int> cnt(256, 0);
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; ++right) {
        unsigned char c = s[right];
        cnt[c]++;

        // 出现重复字符，缩小窗口
        while (cnt[c] > 1) {
            cnt[(unsigned char)s[left]]--;
            left++;
        }

        // 当前窗口合法，更新最长长度
        ans = max(ans, right - left + 1);
    }

    return ans;
}