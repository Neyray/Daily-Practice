//任务处理系统的等待时间计算
#include <iostream>
#include <vector>
#include <queue>
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
    cin.ignore();

    vector<Box>tasks;

    for(int i=0;i<N;++i){
        int arr,exe;
        cin>>arr>>exe;

        //不能用new Box来创建，这返回的是指针类型！！！
        Box b(arr,exe);
        tasks.push_back(b);
    }

    stable_sort(tasks.begin(),tasks.end(),[](Box b1,Box b2){return b1.arrival<b2.arrival;});

    int ans=0;
    int time=0;
    int n=tasks.size();
    for(int i=0;i<n;++i){
        Box b=tasks[i];
        if(i==0){
            time+=b.arrival+b.execution;
        }
        else{
            if(time>b.arrival){
                ans+=time-b.arrival;
                time+=b.execution;
            }
            else{
                time=b.arrival+b.execution;
            }
        }
    }
    cout<<ans;

    return 0;
}