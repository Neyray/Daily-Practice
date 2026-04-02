//KMP算法
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> buildNext(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m + 1);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++; j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

vector<int> kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return {}; // 模式串为空的处理

    vector<int> next = buildNext(pattern);
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < n) {
        // 修正点 1: 必须处理 j == -1 的情况
        if (j == -1 || text[i] == pattern[j]) {
            i++; 
            j++;
        } else {
            j = next[j];
        }

        if (j == m) {
            // 修正点 2: 起始下标应为 i - m
            result.push_back(i - m);
            j = next[j]; // 继续匹配（寻找重叠匹配）
        }
    }
    return result;
}

int main() {
    string text = "ABC ABCDAB ABCDABCDABDE";
    string pattern = "ABCDABD";
    vector<int> res = kmpSearch(text, pattern);
    
    for (int pos : res) {
        cout << "Pattern found at index: " << pos << endl;
    }
    return 0;
}