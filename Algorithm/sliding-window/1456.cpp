// 定长子串中元音的最大数目
#include <iostream>
#include <string>
using namespace std;


int maxVowels(string s, int k) {
    int n = s.size();

    auto isVowel = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    };

    int sum = 0;

    // 初始化第一个窗口
    for (int i = 0; i < k; ++i) {
        sum += isVowel(s[i]);
    }

    int ans = sum;

    // 定长滑动窗口
    for (int i = k; i < n; ++i) {
        sum += isVowel(s[i]);      // 右侧字符进入
        sum -= isVowel(s[i - k]);  // 左侧字符离开

        ans = max(ans, sum);
    }

    return ans;
}