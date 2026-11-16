// 用栈实现队列
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
public:
    // st1表示实际存储的栈,st2表示临时栈
    stack<int>st1,st2;


    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        while(!st1.empty()){
            int num=st1.top();
            st1.pop();
            st2.push(num);
        }

        int result=st2.top();st2.pop();
        while(!st2.empty()){
            int num=st2.top();st2.pop();
            st1.push(num);
        }

        return result;
    }

    int peek() {
        while(!st1.empty()){
            int num=st1.top();
            st1.pop();
            st2.push(num);
        }

        int result=st2.top();
        while(!st2.empty()){
            int num=st2.top();st2.pop();
            st1.push(num);
        }

        return result;
    }

    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */