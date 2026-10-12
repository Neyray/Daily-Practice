// 最长定差子序列
// 由于是定差，所以每个元素的前驱是固定的，从而不需要固定i，对i前面的元素遍历，只用一层循环即可，不连续问题并不意味着一定要使用两层循环
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int,int> dp;
    int ans=0;

    for(int i=0;i<arr.size();++i){
        dp[arr[i]]=dp[arr[i]-difference]+1;
        ans=max(ans,dp[arr[i]]);
    }

    return ans;
}
