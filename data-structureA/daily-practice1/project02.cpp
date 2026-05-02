//栈的排序，只能使用一个辅助栈
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;

    stack<int>st1;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        st1.push(num);
    }

    stack<int>st2;
    while(!st1.empty()){
        //将st1顶部元素取出来
        int num1=st1.top();
        st1.pop();

        //与st2顶部元素进行比较
        if(st2.empty()){
            st2.push(num1);
        }
        else{
            //一直循环直到st2的顶部元素大于num1，或者st2为空

            //一定一定要在访问st.top()前判断非空，不然会导致运行时错误！！！
            while(!st2.empty() && num1>st2.top()){
                int ans=st2.top();
                st2.pop();
                st1.push(ans);
            }
            st2.push(num1);
        }
    }

    //进行输出
    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }

    return 0;
}