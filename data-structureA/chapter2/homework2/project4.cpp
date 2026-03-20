//进行后缀表达式的求解
// 每个样例是一行，为有效的表达式，每个数字和运算符号之间用“,”隔开

//无法处理多位数问题


#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stack>
using namespace std;

int calculate(string input){
    int n=input.size();
    stack<int>st;
    for(int i=0;i<n;++i){
        if(isdigit(input[i])){
            st.push(input[i]-'0');
        }
        else if(input[i]=='+'){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(b+a);
        }
        else if(input[i]=='*'){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.top();
            st.push(b*a);
        }
        else if(input[i]=='-'){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.top();
            st.push(b-a);
        }
        else if(input[i]=='/'){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.top();
            st.push(b/a);
        }
    }

    return st.top();
}

int main(){
    ifstream inFile("in.txt");
    string str;
    getline(inFile,str);

    string tokens="";
    stringstream ss(str);
    string ch;
    while(getline(ss,ch,',')){
        tokens+=ch;
    }

    cout<<calculate(tokens);

    return 0;
}