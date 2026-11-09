// 字符串的排列
// 异步排列问题可以考虑维护数组cnt(26)来判定元素出现个数，只要能相互抵消，就说明存在子串
#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (n > m) return false;

    vector<int> cnt(26, 0);

    // 初始化第一个窗口
    for (int i = 0; i < n; ++i) {
        cnt[s1[i] - 'a']++;
        cnt[s2[i] - 'a']--;
    }

    // 判断两个字符串的字符频率是否相同
    auto check = [&]() {
        for (int x : cnt) {
            if (x != 0) return false;
        }
        return true;
    };
    // 一定要检查第一个滑动窗口！！！
    if (check()) return true;

    // 定长滑动窗口
    for (int i = n; i < m; ++i) {
        cnt[s2[i] - 'a']--;       // 右侧字符进入
        cnt[s2[i - n] - 'a']++;   // 左侧字符离开

        if (check()) return true;
    }

    return false;
}