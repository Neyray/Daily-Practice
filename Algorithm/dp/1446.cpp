// 连续字符
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxPower(string s) {
    int n=s.length();

    vector<int> dp(n,1);
    int ans=1;
    for(int i=1;i<n;++i){
        if(s[i]==s[i-1]){
            dp[i]=dp[i-1]+1;
        }
        ans=max(dp[i],ans);
    }

    return ans;
}