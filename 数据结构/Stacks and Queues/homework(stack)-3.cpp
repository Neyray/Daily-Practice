/*假设一算术表达式中包括三种括号：圆括号"（"和"）"，方括号"["和"]"，花括号"{"和"}"，且三种括号可按意 次序嵌套使用，试编写程序判定输入的表达式所含的括号是否正确配对出现（已知表达式已存入数据元素为字符的顺序表中）。若匹配，则返回1，否则返回0。
【输入形式】

含括号的算数表达式
【输出形式】

1或者0*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;  // 读取测试组数

    bool isValid = true;  // 用一个布尔变量来标记是否匹配正确
    while (T--) {
        string str;
        cin >> str;  // 读取每组输入的表达式

        stack<char> st;  // 用栈来存储括号


        for (char c : str) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);  // 左括号入栈
            }
            else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    isValid = false;  // 如果栈空了，却遇到右括号，说明不匹配
                    break;
                }
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    isValid = false;  // 如果栈顶元素不匹配，说明不合法
                    break;
                }
            }
        }

        // 如果栈不为空，说明还有多余的左括号没有匹配
        if (!st.empty()) {
            isValid = false;
        }

    }
    // 输出结果
    if (isValid) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }


    return 0;
}
