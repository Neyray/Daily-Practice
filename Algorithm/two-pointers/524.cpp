// 通过删除字母匹配到字典里最长单词
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> nxt;

void preprocess(const string& t) {
    int n = t.size();
    nxt.assign(n + 1, vector<int>(26, -1));

    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = nxt[i + 1];
        nxt[i][t[i] - 'a'] = i;
    }
}

bool isSubsequence(const string& dict) {
    int p = 0;

    for (char c : dict) {
        int k = c - 'a';

        int idx = nxt[p][k];
        if (idx == -1) return false;

        p = idx + 1;
    }

    return true;
}

string findLongestWord(string s, vector<string>& dictionary) {
    // 只预处理一次
    preprocess(s);

    int ans = 0;
    string target = "";

    for (const string& str : dictionary) {
        if (isSubsequence(str)) {
            // 优先选择长度更长的，长度相同时选择字典序更小的，直接用target>str来比较字典序
            if (str.length() > ans ||
                (str.length() == ans && str < target)) {
                target = str;
                ans = str.length();
            }
        }
    }

    return target;
}