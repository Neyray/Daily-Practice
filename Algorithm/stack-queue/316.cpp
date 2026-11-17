// 去除重复字母
#include <iostream>
#include <vector>
#include <string>
using namespace std;


string removeDuplicateLetters(string s) {
    vector<int> cnt(26, 0);
    vector<bool> visited(26, false);

    // 统计每个字符出现次数
    for (char ch : s) {
        cnt[ch - 'a']++;
    }

    string st;

    for (char ch : s) {
        int x = ch - 'a';

        // 当前字符已经处理过，跳过
        cnt[x]--;

        if (visited[x]) {
            continue;
        }

        // 删除左边较大的字符
        while (!st.empty() &&
               st.back() > ch &&
               cnt[st.back() - 'a'] > 0) {

            visited[st.back() - 'a'] = false;
            st.pop_back();
        }

        st.push_back(ch);
        visited[x] = true;
    }

    return st;
}
