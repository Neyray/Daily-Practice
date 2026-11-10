// 替换后的最长重复字符
#include <iostream>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();

    int left = 0;
    int ans = 0;
    int maxFreq = 0;

    vector<int> cnt(26, 0);

    for (int right = 0; right < n; ++right) {
        // 加入新字符
        int c = s[right] - 'A';
        cnt[c]++;

        // 更新历史最大字符频次
        maxFreq = max(maxFreq, cnt[c]);

        // 需要替换的字符数量超过 k
        while (right - left + 1 - maxFreq > k) {
            cnt[s[left] - 'A']--;
            left++;
        }

        // 更新最长长度
        ans = max(ans, right - left + 1);
    }

    return ans;
}