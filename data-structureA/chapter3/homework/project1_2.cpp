//任务处理系统的等待时间计算
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Box{
    int arrival;
    int execution;
    Box(int a,int e):arrival(a),execution(e){}
};

int main(){
    int N;
    cin>>N;

    stack<Box>st;
    for(int i=0;i<N;++i){
        int arr,exe;
        cin>>arr>>exe;
        Box b(arr,exe);

        if(st.empty()){
            st.push(b);
        }
        else{
            if(st.top().arrival<=b.arrival){
                st.push(b);
            }
            else{
                stack<Box>st2;
                while(!st.empty() && st.top().arrival>b.arrival){
                    Box p=st.top();
                    st.pop();
                    st2.push(p);
                }
                st.push(b);
                while(!st2.empty()){
                    Box q=st2.top();
                    st2.pop();
                    st.push(q);
                }
            }
        }
    }
    //将栈进行倒置
    stack<Box>tasks;
    while(!st.empty()){
        Box p=st.top();
        tasks.push(p);
        st.pop();
    }

    //进行计算
    int time=0;
    int ans=0;
    int i=0;
    while(!tasks.empty()){
        Box p=tasks.top();
        tasks.pop();

        //第一个元素
        if(i==0){
            time+=p.arrival+p.execution;
        }
        else{
            //来早了
            if(time>p.arrival){
                ans+=time-p.arrival;
                time+=p.execution;
            }
            //来晚了
            else{
                time=p.arrival+p.execution;
            }
        }
        i++;
    }

    cout<<ans;

    return 0;
}