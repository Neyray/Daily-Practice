// 找到字符串中所有字母异位词
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int n = s.length();
    int m = p.length();

    // 模式串比原串长，不可能存在匹配
    if (m > n) return {};

    vector<int> cnt(26, 0);

    // 初始化第一个窗口
    for (int i = 0; i < m; ++i) {
        cnt[p[i] - 'a']++;
        cnt[s[i] - 'a']--;
    }

    auto check = [&]() {
        for (int x : cnt) {
            if (x != 0) return false;
        }
        return true;
    };

    vector<int> ans;

    // 检查第一个窗口
    if (check()) ans.push_back(0);

    // 定长滑动窗口
    for (int i = m; i < n; ++i) {
        cnt[s[i] - 'a']--;       // 右侧字符进入
        cnt[s[i - m] - 'a']++;   // 左侧字符离开

        if (check()) {
            ans.push_back(i - m + 1);
        }
    }

    return ans;
}