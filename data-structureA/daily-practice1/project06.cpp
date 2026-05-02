//循环队列基本操作
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Queue{
public:
    int* data;
    int size;
    int front;
    int rear;

    Queue(int n){
        size=n;
        data=new int[n];
        front=rear=0;
    }

    void push(int n){
        if((rear+1)%size==front){
            cout<<"FULL"<<endl;
            return;
        }
        else{
            rear=(rear+1)%size;
            data[rear]=n;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            front=(front+1)%size;
            cout<<data[front]<<endl;
        }
    }
    void getFront(){
        if(front==rear){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            int head=(front+1)%size;
            cout<<data[head]<<endl;
        }
    }
    void getRear(){
        if(front==rear){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            cout<<data[rear]<<endl;
        }
    }
    void getSize(){
        int length=(rear-front+size)%size;
        cout<<length<<endl;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    cin.ignore();
    
    Queue q(n+1);
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

        if(input[0]=="ENQUEUE"){
            int num=stoi(input[1]);
            q.push(num);
        }
        else if(input[0]=="DEQUEUE"){
            q.pop();
        }
        else if(input[0]=="FRONT"){
            q.getFront();
        }
        else if(input[0]=="REAR"){
            q.getRear();
        }
        else if(input[0]=="SIZE"){
            q.getSize();
        }
        else continue;
    }
    return 0;
}