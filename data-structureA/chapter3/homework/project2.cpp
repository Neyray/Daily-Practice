//队列-超市模拟(1)，有n个队列
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct Queue{
    int front;
    int rear;
    vector<string>data;

    Queue(){
        front=rear=-1;
    }

    bool empty(){
        return front==rear;
    }
    bool push(string str){
        rear+=1;
        data.push_back(str);  // 替换 data[rear]=str
        return true;
    }
    bool pop(string& s){
        if(front==rear)return false;

        front+=1;
        s=data[front];
        return true;
    }
    bool gettop(string& s){
        if(front==rear)return false;

        int head=front+1;
        s=data[head];
        return true;
    }
};




int main(){
    int n;
    cin>>n;
    cin.ignore();

    vector<Queue>q(n);
    for(int i=0;i<n;++i){
        string str;
        getline(cin,str);
        stringstream ss(str);

        string token;
        while(getline(ss,token,' ')){
            if(!token.empty() && token.back()=='\r'){
                token.pop_back();
            }
            if(token.empty())continue;

            q[i].push(token);
        }
    }

    cout<<"DEPARTS"<<endl;
    cin.ignore();
    string str;
    while(getline(cin,str)){
        if(!str.empty() && str.back()=='\r') str.pop_back();

        //处理的每一行
        if(str!=""){
            stringstream ss(str);

            vector<string>input;
            string token;

            //每一行读入的每一个字符串
            while(getline(ss,token,' ')){
                if(!token.empty() && token.back()=='\r'){
                    token.pop_back();
                }
                if(token.empty())continue;

                input.push_back(token);
            }


            if(input[0]=="LEAVES"){
                int ans=stoi(input[1])-1;
                if(!q[ans].empty()){
                    string e;
                    q[ans].pop(e);
                    cout<<e<<endl;
                }
            }
            else if(input[0]=="ENTERS"){
                string name=input[1];
                int ans=stoi(input[2])-1;
                q[ans].push(name);
            }
            else{
                continue;
            }
        }
    }

    cout<<endl;
    cout<<"FINAL CONTENTS"<<endl;

    //总共有n个队列
    for(int i=0;i<n;++i){
        cout << "queue " << i+1 << ": ";  // i+1，不是i
        if(q[i].empty()){
            cout<<endl;
        }
        else{
            while(!q[i].empty()){
                string cus;
                q[i].pop(cus);
                cout<<cus<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}