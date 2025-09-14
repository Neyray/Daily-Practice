#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> count(26, 0);  // 记录每个字符剩余的出现次数
    vector<bool> inStack(26, false);  // 记录字符是否已经在栈中

    // 统计每个字符在字符串中出现的次数
    for (char c : s) {
        count[c - 'a']++;
    }

    stack<char> st;

    for (char c : s) {
        int idx = c - 'a';
        // 如果当前字符已经在栈中，跳过
        if (inStack[idx]) {
            count[idx]--;
            continue;
        }

        // 保证栈中的字符按字典序排列，并且如果栈顶字符后面还会出现，就可以弹出
        while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
            inStack[st.top() - 'a'] = false;
            st.pop();
        }

        st.push(c);
        inStack[idx] = true;
        count[idx]--;
    }

    // 将栈中的字符拼接成最终字符串
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    cout << "字母排序系统，可将英文字母进行排序处理并保证字母序最小" << endl;
    string s1;
    cout << "请输入英语字母，并注意字母之间不要有空格，在一行内完成。" << endl;
    cin >> s1;

    cout << removeDuplicateLetters(s1);
    system("pause");
    return 0;
}
