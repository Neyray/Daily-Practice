//链栈基本操作
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int d):data(d),next(NULL){}
};


class Stack{
public:
    Node* head;
    Stack(){
        head=new Node();
    }

    void push(int n){
        Node* p=new Node(n);
        p->next=head->next;
        head->next=p;
    }
    void pop(){
        if(head->next==NULL){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            cout<<head->next->data<<endl;
            Node* p=head->next;
            head->next=p->next;
            delete p;
        }
    }
    void gettop(){
        if(head->next==NULL){
            cout<<"EMPTY"<<endl;
            return;
        }
        else{
            cout<<head->next->data<<endl;
        }
    }
    void isEmpty(){
        if(head->next==NULL){cout<<"YES"<<endl;return;}
        else{cout<<"NO"<<endl;return;}
    }
};

int main(){
    int m;
    cin>>m;
    cin.ignore();

    Stack st;
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
        else if(input[0]=="IS_EMPTY"){
            st.isEmpty();
        }
        else continue;
    }

    return 0;
}