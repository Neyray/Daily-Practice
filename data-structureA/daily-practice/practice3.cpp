//用栈实现队列
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    stack<int>st1;
    stack<int>st2;

    //总共有n行输入
    while(n>0){
        string str;
        getline(cin,str);    //当前这一行所有的字符
        stringstream ss(str);

        //一定要注意形式！！！token必须是string类型
        string token;

        //这里是处理每一行有多个以空格分开的数据
        while(getline(ss,token,' ')){
            if(token=="ENQUEUE")continue;
            else if(isdigit(token[0])){
                st1.push(stoi(token));
            }
            else if(token=="DEQUEUE"){
                //把st1全部倒入st2，实现顺序反转（队头在st2顶部）
                while(!st1.empty()){
                    int num=st1.top();
                    st1.pop();
                    st2.push(num);
                }
                //进行输出
                if(!st2.empty()){
                    cout<<st2.top()<<endl;
                    st2.pop();
                } else {
                    cout<<"EMPTY"<<endl;
                }
                //把st2剩余数据倒回st1
                while(!st2.empty()){
                    int num=st2.top();
                    st2.pop();
                    st1.push(num);
                }
            }
            else if(token=="PEEK"){
                //把st1全部倒入st2，实现顺序反转（队头在st2顶部）
                while(!st1.empty()){
                    int num=st1.top();
                    st1.pop();
                    st2.push(num);
                }
                //进行输出
                if(!st2.empty()){
                    cout<<st2.top()<<endl;
                } else {
                    cout<<"EMPTY"<<endl;
                }
                //把st2剩余数据倒回st1
                while(!st2.empty()){
                    int num=st2.top();
                    st2.pop();
                    st1.push(num);
                }
            }
        }
        n--;
    }

    return 0;
}