//后缀表达式求值
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    getline(cin,str);

    stringstream ss(str);
    string token;

    stack<int>st;
    while(getline(ss,token,' ')){
        if(!token.empty() && token.back()=='\r'){
            token.pop_back();
        }
        if(token.empty())continue;

        //！！！
        //注意判断条件：isdigit判断的是字符类型
        if(token.size() > 1 || isdigit(token[0])){
            st.push(stoi(token));
        }
        else if(token=="+"){
            int a,b;
            if(!st.empty()){
                a=st.top();
                st.pop();
            }
            if(!st.empty()){
                b=st.top();
                st.pop();
            }
            st.push(b+a);
        }
        else if(token=="-"){
            int a,b;
            if(!st.empty()){
                a=st.top();
                st.pop();
            }
            if(!st.empty()){
                b=st.top();
                st.pop();
            }
            st.push(b-a);
        }
        else if(token=="*"){
            int a,b;
            if(!st.empty()){
                a=st.top();
                st.pop();
            }
            if(!st.empty()){
                b=st.top();
                st.pop();
            }
            st.push(b*a);
        }
        else if(token=="/"){
            int a,b;
            if(!st.empty()){
                a=st.top();
                st.pop();
            }
            if(!st.empty()){
                b=st.top();
                st.pop();
            }
            st.push(b/a);
        }
    }

    if(!st.empty()){
        int result=st.top();
        cout<<result;
    }

    return 0;
}