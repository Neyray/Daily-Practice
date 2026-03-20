#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
#include <stack>
using namespace std;

int main(){
    ifstream inFile("in.txt");
    if(!inFile.is_open()){          // 检查文件是否打开成功
        cerr << "文件打开失败" << endl;
        return 1;
    }

    string str;
    while(getline(inFile, str)){    // 循环读每一行
        if(str.empty()) continue;   // 跳过空行

        stack<int> st;              // 每行用新的栈
        stringstream ss(str);
        string token;

        while(getline(ss, token, ',')){
            if(token.empty()) continue;  // 跳过空token
            if(isdigit(token[0]) || (token.size()>1 && token[0]=='-')){
                st.push(stoi(token));
            } else {
                if(st.size() < 2) continue;  // 防止栈不足时崩溃
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(token == "+") st.push(b + a);
                else if(token == "-") st.push(b - a);
                else if(token == "*") st.push(b * a);
                else if(token == "/") st.push(b / a);
            }
        }

        if(!st.empty())
            cout << st.top() << "\n";
    }

    return 0;
}