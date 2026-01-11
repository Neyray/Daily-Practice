// 字符串操作：压缩、扩展、最长公共前缀
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 压缩字符串：aaabbc -> a3b2c1
string compress(const string& s) {
    if (s.empty()) return "";

    string result = "";
    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        }
        else {
            result += s[i - 1];
            result += to_string(count);
            count = 1;
        }
    }

    return result.length() < s.length() ? result : s;
}

// 扩展字符串：a3b2 -> aaabb
string expand(const string& s) {
    string result = "";
    int i = 0;

    while (i < s.length()) {
        char current_char = s[i];

        // 检查下一个字符是否是数字
        if (i + 1 < s.length() && isdigit(s[i + 1])) {
            i++;  // 移动到数字位置

            // 提取数字（可能有多位）
            int repeat_count = 0;
            while (i < s.length() && isdigit(s[i])) {
                repeat_count = repeat_count * 10 + (s[i] - '0');
                i++;
            }

            // 将字符重复指定次数
            for (int j = 0; j < repeat_count; j++) {
                result += current_char;
            }
        }
        else {
            // 如果没有数字，只添加一次字符
            result += current_char;
            i++;
        }
    }

    return result;
}

// 最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.length() && j < strs[i].length()
            && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }

    return prefix;
}

int main() {
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        // 压缩字符串
        string s;
        getline(cin, s);
        cout << compress(s) << endl;
    }
    else if (choice == 2) {
        // 扩展字符串
        string s;
        getline(cin, s);
        cout << expand(s) << endl;
    }
    else if (choice == 3) {
        // 最长公共前缀
        int n;
        cin >> n;
        cin.ignore();
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            getline(cin, strs[i]);
        }
        cout << longestCommonPrefix(strs) << endl;
    }

    return 0;
}