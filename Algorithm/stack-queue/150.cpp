// 逆波兰表达式求值
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s:tokens){
            if(s=="+"){
                int a1,b1;
                if(!st.empty()){
                    string a=st.top();
                    a1=stoi(a);

                    st.pop();
                }
                if(!st.empty()){
                    string b=st.top();
                    b1=stoi(b);

                    st.pop();
                }

                int num=b1+a1;
                st.push(to_string(num));
            }else if(s=="-"){
                int a1,b1;
                if(!st.empty()){
                    string a=st.top();
                    a1=stoi(a);

                    st.pop();
                }
                if(!st.empty()){
                    string b=st.top();
                    b1=stoi(b);

                    st.pop();
                }

                int num=b1-a1;
                st.push(to_string(num));
            }else if(s=="*"){
                int a1,b1;
                if(!st.empty()){
                    string a=st.top();
                    a1=stoi(a);

                    st.pop();
                }
                if(!st.empty()){
                    string b=st.top();
                    b1=stoi(b);

                    st.pop();
                }

                int num=b1*a1;
                st.push(to_string(num));
            }else if(s=="/"){
                int a1,b1;
                if(!st.empty()){
                    string a=st.top();
                    a1=stoi(a);

                    st.pop();
                }
                if(!st.empty()){
                    string b=st.top();
                    b1=stoi(b);

                    st.pop();
                }

                int num=b1/a1;
                st.push(to_string(num));
            }else{
                st.push(s);
            }
        }


        return stoi(st.top());
    }
};