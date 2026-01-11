#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string temp = "";

    // 错误1：索引越界风险
    for (int i = 0; i <= s.length(); i++) {  // 应该是 i < s.length()
        if (s[i] == ' ' || i == s.length()) {
            if (!temp.empty()) {
                words.push_back(temp);
                temp = "";
            }
        }
        else {
            temp += s[i];
        }
    }

    string result = "";
    // 错误2：反向遍历时索引错误
    for (int i = words.size(); i >= 0; i--) {  // 应该是 i = words.size()-1
        result += words[i];
        if (i > 0) result += " ";
    }
    return result;
}

int main() {
    string input = "hello world";
    string output = reverseWords(input);
    cout << "反转结果: " << output << endl;
    return 0;
}