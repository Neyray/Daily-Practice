/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            // 关键修复1：先检查栈是否为空
            if (st.empty()) return false;

            char topChar = st.top();
            st.pop();  // 关键修复2：总是弹出栈顶

            // 关键修复3：正确匹配括号类型
            if (c == ')' && topChar != '(') {
                return false;
            }
            else if (c == ']' && topChar != '[') {  // 修复：检查'['而不是'{'
                return false;
            }
            else if (c == '}' && topChar != '{') {
                return false;
            }
        }
    }

    // 关键修复4：最终检查栈是否为空
    return st.empty();
}

int main() {
    string s = "()[]{}";

    if (isValid(s) == true) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}