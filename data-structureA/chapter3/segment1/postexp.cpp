#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int isPrime(char ch){
    if(ch=='-'||ch=='+')return 0;
    else if(ch=='*'||ch=='/')return 1;
    else return -1;  // 处理 '(' 等情况
}

string exp(string str){
    int n=str.size();
    stack<char>st;
    string ans="";

    int i=0;
    char ch,e;
    while(i<n){
        char ch=str[i];

        if(ch=='('){
            st.push(ch);
        }
        else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                e=st.top();
                ans+=e;
                st.pop();
            }
            //弹出(
            st.pop();
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            while(!st.empty() && isPrime(st.top())>=isPrime(ch)){
                e=st.top();
                ans+=e;
                st.pop();
            }
            //再将这个运算符放进去
            st.push(ch);
        }
        else{
            ans+=ch;
            i++;
            while(i<n && isdigit(str[i])){
                ans+=str[i];
                i++;
            }
            //这时候的i不是数字了，所以需要退一个，因为之后有i+1操作
            i--;

            //使用#来分隔
            ans+='#';
        }
        i++;
    }

    //不要忘了这一步！！！
    while(!st.empty()){
        char e=st.top();
        ans+=e;
        st.pop();
    }

    return ans;
}