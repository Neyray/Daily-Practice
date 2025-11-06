//括号匹配问题
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(char expr[])
{
    stack<char> st;
    int len = strlen(expr);  // 获取字符串实际长度

    for (int i = 0; i < len; ++i) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            // 检查栈是否为空（重要！）
            if (st.empty()) {
                return false;
            }

            char topChar = st.top();
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
        // 其他字符忽略，继续处理
    }

    // 最后检查栈是否为空
    return st.empty();
}

int main()
{
    char expr1[100];
    cin >> expr1;
    cout << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}