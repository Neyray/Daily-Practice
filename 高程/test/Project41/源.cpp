// 回溯算法 - 全排列
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutation(string s, int start, vector<string>& result) {
    if (start == s.length() - 1) {
        result.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);
        permutation(s, start + 1, result);
        swap(s[start], s[i]);
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> result;
    permutation(s, 0, result);

    for (string p : result) {
        cout << p << endl;
    }

    return 0;
}