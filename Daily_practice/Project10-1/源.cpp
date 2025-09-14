#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

pair<int, string> longestUniqueSubstring(const string& s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;
    int bestStart = 0;

    for (int end = 0; end < s.length(); ++end) {
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[end]] + 1);
        }
        charIndexMap[s[end]] = end;

        // 更新最大子串的长度及其起始位置
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            bestStart = start;
        }
    }

    // 截取最长子串
    string longestSubstring = s.substr(bestStart, maxLength);
    return { maxLength, longestSubstring };
}

int main() {
    string s;
    cout << "请输入一个字符串: ";
    cin >> s;

    auto result = longestUniqueSubstring(s);
    cout << "最长不含重复字符的子串长度为: " << result.first << endl;
    cout << "最长不含重复字符的子串为: " << result.second << endl;

    return 0;
}
