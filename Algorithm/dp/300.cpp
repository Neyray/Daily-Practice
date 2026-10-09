// 最长递增子序列
#include <iostream>
#include <vector>
using namespace std;

// dp[i]表示以i结尾的子序列最长的值，由于不一定是最后一个元素为末尾的最大，所以需要维护一个result变量来保存最大值
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1);
    int result=1;

    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        result=max(result,dp[i]);
    }

    return result;
}
