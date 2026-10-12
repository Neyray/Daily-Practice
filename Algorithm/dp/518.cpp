// 零钱兑换II
#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    // dp[i]表示凑成总金额i的硬币组合数
    vector<int> dp(amount+1,0);
    dp[0]=1;

    for(int coin:coins){
        for(int i=coin;i<=amount;++i){
            dp[i]+=dp[i-coin];
        }
    }

    return dp[amount];
}
