//括号匹配问题
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n=str.size();
    stack<char>st;

    for(int i=0;i<n;++i){
        char ch=str[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }
        else if(ch==')'){
            if(st.empty()){cout<<"NO";return -1;}

            char e=st.top();
            if(e!='('){cout<<"NO";return -1;}
            else st.pop();
        }
        else if(ch==']'){
            if(st.empty()){cout<<"NO";return -1;}

            char e=st.top();
            if(e!='['){cout<<"NO";return -1;}
            else st.pop();
        }
        else if(ch=='}'){
            if(st.empty()){cout<<"NO";return -1;}

            char e=st.top();
            if(e!='{'){cout<<"NO";return -1;}
            else st.pop();
        }
    }

    if(st.empty()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}