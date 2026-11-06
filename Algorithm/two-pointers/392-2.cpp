// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 当 S 很短、T 很长，而且需要重复查询大量不同的 S 时，可以避免反复扫描 T，直接访问数组
vector<int> pos[26];

// 预处理 T，只做一次
void preprocess(string& t) {
    for(int i=0;i<t.size();++i){
        pos[t[i]-'a'].push_back(i);
    }
}

// 对每个 S 调用一次
bool isSubsequence(string s) {
    int p=-1;

    for(char c:s){
        int k=c-'a';

        // 找第一个位置严格大于 p 的字符
        auto it=upper_bound(pos[k].begin(),pos[k].end(),p); // 二分查找

        if(it==pos[k].end())return false;

        p=*it;
    }

    return true;
}