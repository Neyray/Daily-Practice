//条件反转循环队列
#include <iostream>
#include <string>
using namespace std;

class Stack{
public:
    int top;
    int capacity;
    int length;
    int* data;

    Stack(int c){
        top=-1;
        length=0;
        capacity=c;
        data=new int[capacity];
    }

    bool empty(){
        return length==0;
    }
    bool push(int e){
        if(length==capacity)return false;

        top++;
        data[top]=e;
        length++;
        return true;
    }
    bool pop(int& e){
        if(length==0)return false;

        e=data[top];
        top--;
        return true;
    }
    bool gettop(int& e){
        if(length==0)return false;

        e=data[top];
        return true;
    }
};

//front指向第一个元素的前驱，存在哨兵节点
class Cqueue{
public:
    int front;
    int rear;
    int maxSize;
    int* data;
    Cqueue(int m){
        front=rear=0;
        maxSize=m;
        data=new int[maxSize];
    }
    ~Cqueue(){
        delete[]data;
    }
    bool empty(){
        return rear==front;
    }
    bool push(int e){
        if((rear+1)%maxSize==front)return false;

        rear=(rear+1)%maxSize;
        data[rear]=e;
        return true;
    }
    bool pop(int& e){
        if(front==rear)return false;

        front=(front+1)%maxSize;
        e=data[front];
        return true;
    }
    bool gettop(int& e){
        if(front==rear)return false;

        int head=(front+1)%maxSize;
        e=data[head];
        return true;
    }
};

int main(){
    int n;
    cin>>n;

    Cqueue q(n+1);

    int arr[100];//用来存储-1出现的下标
    int j=0;//j是arr的下标，同时也表示有几个-1
    for(int i=0;i<n;++i){
        int num;
        cin>>num;

        if(num==-1){
            arr[j]=i;
            j++;
        }
        else{
            q.push(num);
        }
    }

    //此时队列里面全是不为-1的数字
    Stack st(n+1);
    int size=j;//size表示-1的个数

    //将队列中的数字放入栈中
    while(!q.empty()){
        int e;
        q.pop(e);

        st.push(e);
    }

    //执行输出操作
    int s=0,t=0;//s用来统计输出的个数，t用来遍历arr数组

    //不能写!st.empty()，因为可能全为-1
    while(s<n){
        if(t<size && arr[t]==s){
            cout<<"-1 ";
            t++;
        }
        else{
            int e;
            st.pop(e);
            cout<<e<<" ";
        }
        s++;
    }

    return 0;
}