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

        // ��������Ӵ��ĳ��ȼ�����ʼλ��
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            bestStart = start;
        }
    }

    // ��ȡ��Ӵ�
    string longestSubstring = s.substr(bestStart, maxLength);
    return { maxLength, longestSubstring };
}

int main() {
    string s;
    cout << "������һ���ַ���: ";
    cin >> s;

    auto result = longestUniqueSubstring(s);
    cout << "������ظ��ַ����Ӵ�����Ϊ: " << result.first << endl;
    cout << "������ظ��ַ����Ӵ�Ϊ: " << result.second << endl;

    return 0;
}
