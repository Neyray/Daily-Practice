#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<int> numSt;       // 存重复次数
    stack<string> strSt;    // 存每一层已经拼好的字符串
    string cur = "";        // 当前层正在构建的字符串
    int num = 0;

    for (char ch : str) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // 支持多位数
        } else if (ch == '[') {
            numSt.push(num);
            strSt.push(cur);  // 把当前层保存起来
            num = 0;
            cur = "";          // 开新的一层
        } else if (isalpha(ch)) {
            cur += ch;
        } else if (ch == ']') {
            int times = numSt.top(); numSt.pop();
            //prev保存的是之前的字符串
            string prev = strSt.top(); strSt.pop();
            string repeated = "";
            for (int k = 0; k < times; k++) repeated += cur;
            cur = prev + repeated;  // 拼回上一层
        }
    }

    cout << cur;
    return 0;
}