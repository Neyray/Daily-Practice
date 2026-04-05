//顺序栈基本操作
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Stack{
public:
    int* data;
    int size;
    int top;
    Stack(int s){
        size=s;
        data=new int[s];
        top=-1;
    }

    void push(int n){
        if(top==size-1){
            cout<<"FULL"<<endl;
            return;
        }
        else{
            top++;
            data[top]=n;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"EMPTY"<<endl;
            return ;
        }
        else{
            cout<<data[top]<<endl;
            top--;
        }
    }
    void gettop(){
        if(top==-1){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            cout<<data[top]<<endl;
        }
    }
    void getsize(){
        cout<<top+1<<endl;
    }
};

int main(){
    int n,m;
    cin>>n>>m;cin.ignore();

    Stack st(n);
    for(int i=0;i<m;++i){
        string str;
        getline(cin,str);
        stringstream ss(str);

        string token;
        vector<string>input;
        while(getline(ss,token,' ')){
            if(!token.empty() && token.back()=='\r'){
                token.pop_back();
            }
            if(token.empty())continue;

            input.push_back(token);
        }

        if(input[0]=="PUSH"){
            int num=stoi(input[1]);
            st.push(num);
        }
        else if(input[0]=="POP"){
            st.pop();
        }
        else if(input[0]=="TOP"){
            st.gettop();
        }
        else if(input[0]=="SIZE"){
            st.getsize();
        }
        else continue;
    }

    return 0;
}