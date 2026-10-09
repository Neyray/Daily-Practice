//爬楼梯
#include <iostream>
#include <vector>
using namespace std;

int climbstairs(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;

    vector<int> dp(n+1,0);
    for(int i=3;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}