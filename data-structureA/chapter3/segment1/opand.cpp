//输入后缀表达式并求值
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int opand(string str){
    int n=str.size();
    stack<int>st;
    int i=0;

    while(i<n){
        char ch=str[i];

        //可能是多位数！！！
        if(isdigit(ch)){
            string num="";
            num+=ch;i++;

            //哪怕数字间使用特殊符号隔开也不影响，因为这一步执行完i就是倒数第一个数字，执行循环到特殊符号，跳过，再执行后面的
            while(i<n && isdigit(str[i])){
                num+=str[i];
                i++;
            }
            //此时的i不是数字，所以需要退回去，等待之后的i+1
            i--;
            st.push(stoi(num));
        }
        else if(ch=='+'){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            st.push(b+a);
        }
        else if(ch=='-'){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            st.push(b-a);
        }
        else if(ch=='*'){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            st.push(b*a);
        }
        else if(ch=='/'){
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            st.push(b/a);
        }
        i++;
    }
    return st.top();
}