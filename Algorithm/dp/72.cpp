//编辑距离
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



// 假设 dp[i][j] 表示将 word1 的前 i 个字符转换成 word2 的前 j 个字符所需的最少操作次数
// dp[i-1][j]+1表示删除字符，dp[i][j-1]+1表示插入字符，dp[i-1][j-1]+1表示替换字符
/*
（1）删除：dp[i-1][j]+1
先将 word1 的前 i-1 个字符转换为 word2 的前 j 个字符，再删除 word1 的第 i 个字符。
（2）插入：dp[i][j-1]+1
先将 word1 的前 i 个字符转换为 word2 的前 j-1 个字符，再插入 word2 的第 j 个字符。
（3）替换：dp[i-1][j-1]+1
先处理两个字符串各自的前 i-1、j-1 个字符，再把 word1 的第 i 个字符替换为 word2 的第 j 个字符。
*/


int minDistance(string word1, string word2) {
    int m=word1.length();
    int n=word2.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;++i){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;++j){
        dp[0][j]=j;
    }

    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            }
        }
    }
    return dp[m][n];
}