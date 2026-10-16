// 零钱兑换II
// 组合数问题

// 完全背包问题
#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    // dp[i]表示凑成总金额i的硬币组合数
    vector<int> dp(amount+1,0);
    dp[0]=1;


    // 先遍历硬币，意味着逐步限定当前允许使用的硬币种类，这样不会因为硬币顺序不同而重复统计同一组合
    // 如果先遍历金额，dp[3]+=dp[2],dp[3]+=dp[1]会重复计算1+2和2+1的组合数
    for(int coin:coins){
        for(int i=coin;i<=amount;++i){
            dp[i]+=dp[i-coin];
        }
    }

    return dp[amount];
}
