// 目标和
// 0/1背包动态规划
#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    for(int num:nums){
        sum+=num;
    }

    if(abs(target)>sum || (sum+target)%2!=0)return 0;

    int P=(target+sum)/2;

    // dp[i]表示取出元素之和等于i的种数
    vector<int> dp(P+1,0);
    dp[0]=1;

    for(int num:nums){
        for(int j=P;j>=num;--j){
            dp[j]+=dp[j-num];
        }
    }
    return dp[P];
}
