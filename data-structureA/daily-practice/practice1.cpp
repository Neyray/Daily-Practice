//中缀转后缀表达式
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char ch) {
    if (ch == '+' || ch == '-') return 0;
    else if (ch == '*' || ch == '/') return 1;
    else return -1;  // 括号
}

int main() {
    string str;
    cin >> str;

    int n = str.size();
    stack<char> st;
    bool first = true;  // 控制输出空格

    auto output = [&](char c) {
        if (!first) cout << " ";
        cout << c;
        first = false;
    };

    for (int i = 0; i < n; ++i) {
        char ch = str[i];

        // 多位数字：一次性读完整个数
        if (isdigit(ch)) {
            if (!first) cout << " ";
            first = false;
            while (i < n && isdigit(str[i])) {
                cout << str[i];
                i++;
            }
            i--;  // for循环还会i++，先退一步
        }
        else if (ch == '(') {
            st.push(ch);  // 左括号直接入栈
        }
        else if (ch == ')') {
            // 弹出直到遇到左括号
            while (!st.empty() && st.top() != '(') {
                output(st.top());
                st.pop();
            }
            st.pop();  // 丢弃左括号
        }
        else {
            // 普通运算符：弹出所有优先级 >= 当前的
            while (!st.empty() && st.top() != '(' 
                   && priority(st.top()) >= priority(ch)) {
                output(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    // 清空栈
    while (!st.empty()) {
        output(st.top());
        st.pop();
    }
    cout << endl;
    return 0;
}