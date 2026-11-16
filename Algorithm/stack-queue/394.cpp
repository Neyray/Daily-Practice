// 字符串解码
#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "";

        for(char ch : s){
            if(ch == '['){
                st.push("[");
            }
            else if(isdigit(ch)){
                st.push(string(1, ch));
            }
            else if(isalpha(ch)){
                st.push(string(1, ch));
            }
            else if(ch == ']'){
                // 1. 取出括号内部的字符串
                string temp = "";

                while(!st.empty() && st.top() != "["){
                    temp = st.top() + temp;
                    st.pop();
                }

                // 2. 弹出 '['
                st.pop();

                // 3. 取出重复次数
                string num = "";

                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top() + num;
                    st.pop();
                }

                int num1 = stoi(num);

                // 4. 重复字符串
                string origin = temp;

                for(int i = 1; i < num1; ++i){
                    temp += origin;
                }

                // 5. 将解码结果重新压入栈
                st.push(temp);
            }
        }

        // 6. 拼接最终结果
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};