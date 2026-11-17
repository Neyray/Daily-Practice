// 移掉 K 位数字
// 删掉左边的山峰
// 单调栈，从左到右遍历，但是不是“当前元素帮助左边更小的元素确定答案”，而是直接删除，构造新字符串
#include <iostream>
#include <string>
using namespace std;


string removeKdigits(string num, int k) {
    string st;

    for (char ch : num) {
        // 当前数字更小时，删除前面较大的数字
        while (!st.empty() && k > 0 && st.back() > ch) {
            st.pop_back();
            k--;
        }

        st.push_back(ch);
    }

    // 如果还没有删够 k 位，从右边继续删除
    while (k > 0) {
        st.pop_back();
        k--;
    }

    // 去掉前导零
    int i = 0;
    while (i < st.size() && st[i] == '0') {
        i++;
    }

    string ans = st.substr(i);

    return ans.empty() ? "0" : ans;
}
