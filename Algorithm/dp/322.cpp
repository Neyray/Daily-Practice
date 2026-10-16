// 零钱兑换I
// 最优化问题，不需要考虑相同选择不同顺序的问题

// 完全背包问题：可以重复选
// 金额i可以拆成金额j和面额为i-j的硬币，即dp[i]=dp[i-coin]+1
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,amount+1);
    dp[0]=0;

    for(int i=1;i<=amount;++i){
        for(int coin:coins){
            if(i>=coin){
                // i的前驱也是固定的，只有i-coin才能匹配上，所以不必遍历所有小于i的数，思想类似1218最长定差序列
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }

    return dp[amount]==amount+1 ? -1 : dp[amount];
}
