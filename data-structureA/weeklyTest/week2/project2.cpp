//利用顺序栈倒置循环队列元素
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//循环队列
class Cqueue{
public:
    int* data;
    int front;
    int rear;
    int size;

    //front指向第一个元素的前驱，rear指向最后一个元素
    Cqueue(int n){
        size=n;
        data=new int[size];
        front=rear=0;
    }
    void push(int n){
        //队列满了
        if((rear+1)%size==front)return;

        rear=(rear+1)%size;
        data[rear]=n;
    }
    void pop(int& n){
        //队列为空
        if(rear==front)return;

        front=(front+1)%size;
        n=data[front];
    }
    bool isempty(){
        return front==rear;
    }
};

class Stack{
public:
    int size;
    int top;
    int* data;

    Stack(int n){
        size=n;
        top=-1;
        data=new int[n];
    }

    void push(int n){
        if(top==size-1)return;

        top++;
        data[top]=n;
    }

    void pop(int& n){
        if(top==-1)return;

        n=data[top];
        top--;
    }

    void gettop(int& n){
        if(top==-1)return;

        n=data[top];
    }

    bool isempty(){
        return top==-1;
    }
};

int main(){
    int n;
    cin>>n;

    int arr[500];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    //创建循环队列
    Cqueue cq(n+1);//要余留一位
    for(int i=0;i<n;++i){
        cq.push(arr[i]);
    }

    Stack st(n);
    while(!cq.isempty()){
        int num;
        cq.pop(num);
        st.push(num);
    }

    while(!st.isempty()){
        int num;
        st.pop(num);

        cout<<num<<" ";
    }

    return 0;
}