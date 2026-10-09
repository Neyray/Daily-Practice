// 打家劫舍II
// 环形排列，拆成两个线性 DP
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];

    vector<int> dp(n+1,0);
    dp[0]=0;dp[1]=nums[0];

    // 1到n-1
    for(int i=2;i<n;++i){
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }
    int result1=dp[n-1];

    // 2到n
    // 重新初始化dp数组
    dp[0]=0;dp[1]=0;dp[2]=nums[1]; // dp[1]=0表示不考虑第一个房屋，dp[2]=nums[1]表示在不考虑第一个房屋的情况下，前两个房屋最大的钱数只能是只选第二个房屋
    for(int i=3;i<=n;++i){
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
    }
    int result2=dp[n];
    return max(result1,result2);
}
