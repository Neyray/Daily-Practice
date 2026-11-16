// 用队列实现栈
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;

    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        int k=0;
        while(!q1.empty()){
            int num=q1.front();
            q1.pop();
            q2.push(num);

            k++;
        }

        for(int i=1;i<k;++i){
            int num=q2.front();
            q2.pop();
            q1.push(num);
        }

        int result=q2.front();q2.pop();
        return result;
    }

    int top() {
        int k=0;
        while(!q1.empty()){
            int num=q1.front();
            q1.pop();
            q2.push(num);

            k++;
        }

        for(int i=1;i<k;++i){
            int num=q2.front();
            q2.pop();
            q1.push(num);
        }

        int result=q2.front();q2.pop();q1.push(result);
        return result;
    }

    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */