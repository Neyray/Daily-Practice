// 打家劫舍I
// 线性排列，直接 DP
#include <iostream>
#include <vector>
using namespace std;


// dp[i]表示前i个房屋偷的最大钱数，不一定需要包含nums[i]这个数据，所以不需要维护result，由于有报警系统，所以偷第i天(nums[i])的情况下只能累加dp[i-2]，再与dp[i-1]比较
int rob(vector<int>& nums) {
    int n=nums.size();

    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=nums[0];

    for(int i=2;i<=n;++i){
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }

    return dp[n];
}