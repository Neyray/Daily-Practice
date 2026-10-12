// 分割等和子集
// 0/1背包动态规划
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int num:nums){
        sum+=num;
    }

    if(sum%2!=0)return false;

    int target=sum/2;
    // dp[i]表示能否从nums挑出和为i的数，同时满足每个数只用一次
    vector<bool> dp(target+1,false);
    dp[0]=true;

    for(int num:nums){
        for(int j=target;j>=num;--j){
            // 自顶向下，计算 dp[j] 时，右侧的 dp[j-num] 仍然来自处理当前元素之前的状态，不会重复使用当前元素
            dp[j]=dp[j] || dp[j-num];
        }
    }
    return dp[target];
}