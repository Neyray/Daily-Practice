// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 假设 T 和所有 S 只包含小写英文字母

vector<vector<int>> nxt;

void preprocess(string& t) {
    int n=t.size();

    // nxt[i][c]表示 T 中从位置 i 开始，字符 c 第一次出现的位置
    nxt.assign(n+1,vector<int>(26,-1));


    // 从后向前构造
    // 利用 nxt[i+1] 已经计算好的结果，推导出 nxt[i]，再只更改t[i]对应的nxt[i][t[i]-'a']下标
    for(int i=n-1;i>=0;--i){
        nxt[i]=nxt[i+1];

        nxt[i][t[i]-'a']=i;
    }
}

bool isSubsequence(string s) {
    int p=0;

    for(char c:s){
        int k=c-'a';

        // 从 p 开始找字符 c
        int idx=nxt[p][k];

        if(idx==-1)return false;

        // 下一次必须从匹配位置之后开始
        p=idx+1;
    }

    return true;
}