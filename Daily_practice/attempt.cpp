#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> changedString(const string& s) {
    vector<string> str;
    int n = s.size();

    // 空字符串直接返回空
    if (n == 0) {
        return str;
    }
   
    int count = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            str.push_back(string(1, s[i - 1]));
            if (count > 1) {
                str.push_back(to_string(count));
            }
            count = 1;
        }
    }

    // 处理最后一个字符
    str.push_back(string(1, s[n - 1]));
    if (count > 1) {
        str.push_back(to_string(count));
    }

    return str;
}

void printSubstring(const vector<string>& str) {
    int n = str.size();
    if (n == 0)
        return;

    for (int i = 0; i < n; ++i) {
        cout << str[i];
    }
}

int main() {
    string s;
    cout << "请输入字符串：";
    cin >> s;
    vector<string> str = changedString(s);
    printSubstring(str);
    return 0;
}
