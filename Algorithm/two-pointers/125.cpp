// 验证回文串
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    string ans = "";

    for (char c : s) {
        if (isalnum(c)) {
            ans += tolower(c);
        }
    }

    int p1 = 0, p2 = (int)ans.size() - 1;

    while (p1 < p2) {
        if (ans[p1] != ans[p2]) return false;
        p1++;
        p2--;
    }

    return true;
}