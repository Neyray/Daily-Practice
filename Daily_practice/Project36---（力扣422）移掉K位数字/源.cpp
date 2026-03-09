#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    // 遍历 num 字符串中的每个数字
    for (char digit : num) {
        // 当栈不为空且当前数字小于栈顶数字，并且还可以删除数字时
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }

    // 如果还剩下要删除的数字
    while (k > 0) {
        st.pop();
        k--;
    }

    // 构造结果字符串
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;  // 注意这里要倒序加入栈中的元素
        st.pop();
    }

    // 去掉前导零
    int start = 0;
    while (start < result.size() && result[start] == '0') {
        start++;
    }

    result = result.substr(start);

    // 如果结果为空，则返回 "0"
    return result.empty() ? "0" : result;
}

int main() {
    // 示例 1
    string num1 = "1432219";
    int k1 = 3;
    cout << "示例1的输出: " << removeKdigits(num1, k1) << endl;  // 输出 "1219"

    // 示例 2
    string num2 = "10200";
    int k2 = 1;
    cout << "示例2的输出: " << removeKdigits(num2, k2) << endl;  // 输出 "200"

    // 示例 3
    string num3 = "10";
    int k3 = 2;
    cout << "示例3的输出: " << removeKdigits(num3, k3) << endl;  // 输出 "0"

    return 0;
}
