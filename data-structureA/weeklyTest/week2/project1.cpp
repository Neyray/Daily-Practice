//列车编组。使奇数在偶数前面
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
public:
    int size;
    int top;
    T* data;

    Stack(int n){
        size=n;
        top=-1;
        data=new T[n];
    }

    void push(T n){
        if(top==size-1)return;

        top++;
        data[top]=n;
    }

    void pop(T& n){
        if(top==-1)return;

        n=data[top];
        top--;
    }

    void gettop(T& n){
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

    Stack<int> st1(n),st2(n);//st1存储出栈序列，st2存储偶数序列，再把st2放到st1头上，最后将st1倒过来
    Stack<string>ops(n*5);

    for(int i=0;i<n;++i){
        int num=arr[i];
        if(num%2==0){
            //偶数
            st2.push(num);

            //碰到偶数直接in
            ops.push("in");
        }
        else{
            //奇数
            st1.push(num);

            //碰到奇数直接进栈-出栈
            ops.push("in");
            ops.push("out");
        }
    }

    //此时st1里面是正确的奇数出栈序列，st2里面是正确的偶数出栈序列


    //将temp放到st1上面
    while(!st2.isempty()){
        int num;
        st2.pop(num);
        ops.push("out");

        st1.push(num);
    }

    //此时st1,ops都是倒置的，需要倒过来
    Stack<int>result1(n);
    Stack<string>result2(n*5);

    while(!st1.isempty()){
        int num;
        st1.pop(num);

        result1.push(num);
    }
    while(!ops.isempty()){
        string op;
        ops.pop(op);

        result2.push(op);
    }

    //进行输出
    while(!result2.isempty()){
        string op;
        result2.pop(op);

        cout<<op<<" ";
    }
    cout<<endl;

    while(!result1.isempty()){
        int num;
        result1.pop(num);

        cout<<num<<" ";
    }

    return 0;
}