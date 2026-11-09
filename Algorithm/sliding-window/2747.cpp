#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    // 按照请求时间排序
    sort(logs.begin(),logs.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    });

    // 查询时间与原下标
    vector<pair<int,int>> q;
    for(int i=0;i<queries.size();++i){
        q.push_back({queries[i],i});
    }
    sort(q.begin(),q.end());

    // cnt[id] 表示服务器 id 在当前时间窗口中有多少条日志
    vector<int> cnt(n+1,0);
    vector<int> ans(queries.size(),0);

    int left=0,right=0;

    // active 表示当前窗口中至少有一条日志的服务器数量
    int active=0;
    int m=logs.size();

    for(auto [time,idx]:q){
        // 加入时间不超过 time 的日志
        while(right<m && logs[right][1]<=time){
            int id=logs[right][0];

            // 只有服务器的请求次数从 0 变为 1 时，才增加 active
            if(cnt[id]==0)active++;
            cnt[id]++;
            right++;
        }

        // 移除时间小于 time-x 的日志
        while(left<right && logs[left][1]<time-x){
            int id=logs[left][0];

            cnt[id]--;
            if(cnt[id]==0)active--;
            left++;
        }

        ans[idx]=n-active;
    }

    return ans;
}