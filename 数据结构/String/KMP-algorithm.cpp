#include <iostream>
#include <string>
using namespace std;

// 生成最长公共前后缀长度的 next 数组
void GetNext(string t, int* next) {
    int j = 0;          // 前缀指针
    next[0] = 0;        // 初始位置无前缀
    for (int i = 1; i < t.length();) {
        if (t[i] == t[j]) {
            j++;
            next[i] = j; // 当前位置的最长公共前后缀长度
            i++;
        }
        else {
            if (j > 0) {
                j = next[j - 1]; // 回退到前一个位置的最长公共前缀
            }
            else {
                next[i] = 0;     // 无公共前缀
                i++;
            }
        }
    }
}

int KMP(string s, string t) {
    int n = s.length(), m = t.length();
    if (m == 0) return 0;        // 空模式直接匹配
    int* next = new int[m];
    GetNext(t, next);

    //j是用来遍历t字符串的,i遍历字符串s
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == t[j]) {
            i++;
            j++;
            if (j == m) {
                delete[] next;
                return i - m;    // 完全匹配
            }
        }
        else {
            if (j > 0) j = next[j - 1]; // 回退到前一个位置的 next 值
            else i++;
        }
    }
    delete[] next;
    return -1;                   // 未找到
}

int main() {
    string line1 = "ABABABCAB";
    string line2 = "ABCAB";

    cout << KMP(line1, line2);
    return 0;
}