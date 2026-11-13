// 最小覆盖子串
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;


string minWindow(string s, string t) {
    int m=s.size(),n=t.size();
    if(n>m)return "";

    vector<int> cnt(128,0);
    for(char c:t){
        cnt[c]++;
    }

    int left=0;
    int missing=n;
    int ans=INT_MAX;
    int start=0;

    for(int right=0;right<m;++right){
        // 当前字符是窗口需要的字符
        if(cnt[s[right]]>0){
            missing--;
        }
        cnt[s[right]]--;

        // 窗口合法，尝试收缩左边界
        while(missing==0){
            if(right-left+1<ans){
                ans=right-left+1;
                start=left;
            }

            cnt[s[left]]++;

            // 移除了必要字符，窗口不再合法
            if(cnt[s[left]]>0){
                missing++;
            }
            left++;
        }
    }

    return ans==INT_MAX ? "" : s.substr(start,ans);
}