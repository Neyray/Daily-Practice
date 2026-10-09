//单词拆分
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;



// unordered_set<string> 用于快速判断一个单词是否在字典中，平均查找时间复杂度为 O(1)，不计字符串哈希本身的成本

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(),wordDict.end());

    int n=s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;


    // 把问题拆成前j个可拆+j到i可以找到，两个子问题
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            if(!dp[j])continue;//如果前j个字符找不到匹配的，说明这个j不能用来划分

            string word=s.substr(j,i-j);
            if(dict.count(word)){
                dp[i]=true;
                break;//不需要再在这个i内找j了，已经证明前i个字符可以找到
            }
        }
    }
    return dp[n];
}