// 分割回文串
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    int n = s.size();

    // 判断 s[left...right] 是否为回文串
    auto isPalindrome = [&](int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    };

    function<void(int)> dfs = [&](int start) {
        if (start == n) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < n; ++i) {
            // 判断当前子串是否为回文
            if (!isPalindrome(start, i)) {
                continue;
            }

            // 一旦start到i是回文序列，就存入path，并且start设为i+1，继续在后面的字符串找
            path.push_back(s.substr(start, i - start + 1));

            dfs(i + 1);

            path.pop_back();
        }
    };

    dfs(0);// 最外层的循环start永远是0
    return ans;
}