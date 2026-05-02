//用队列实现栈
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int m;
    cin>>m;
    cin.ignore();

    int size=0;//表示队列里的元素个数
    queue<int>q1,q2;

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
            q1.push(num);
            size++;
        }
        else if(input[0]=="POP"){
            if(!q1.empty()){
                //如果只有一个元素
                if(size==1){
                    int num=q1.front();
                    cout<<num<<endl;
                    q1.pop();
                }
                else{
                    int tempsize=size;
                    while(tempsize>=2){
                        int num=q1.front();
                        q1.pop();
                        q2.push(num);
                        tempsize--;
                    }
                    int val=q1.front();
                    q1.pop();
                    cout<<val<<endl;

                    //再把q2的元素倒回q1
                    while(!q2.empty()){
                        int num=q2.front();
                        q2.pop();
                        q1.push(num);
                    }
                }
                size--;
            }
        }
        else if(input[0]=="TOP"){
            if(!q1.empty()){
                //如果只有一个元素
                if(size==1){
                    int num=q1.front();
                    cout<<num<<endl;
                }
                else{
                    int tempsize=size;
                    while(tempsize>=2){
                        int num=q1.front();
                        q1.pop();
                        q2.push(num);
                        tempsize--;
                    }
                    int val=q1.front();
                    q1.pop();
                    cout<<val<<endl;
                    q2.push(val);

                    //再把q2的元素倒回q1
                    while(!q2.empty()){
                        int num=q2.front();
                        q2.pop();
                        q1.push(num);
                    }
                }
            }
        }
        else continue;
    }

    return 0;
}