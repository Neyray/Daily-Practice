// 串联所有单词的子串
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {
    int n=s.size();
    int m=words.size();
    int len=words[0].size();

    vector<int> ans;

    if(n<m*len)return ans;

    // 统计目标单词出现次数
    unordered_map<string,int> need;
    for(string& w:words){
        need[w]++;
    }

    // 枚举不同的起始偏移量
    for(int i=0;i<len;++i){
        int left=i;
        int cnt=0;

        unordered_map<string,int> mp;

        for(int right=i;right+len<=n;right+=len){
            string word=s.substr(right,len);

            // 当前单词不在words中，重置窗口
            if(!need.count(word)){
                mp.clear();
                cnt=0;
                left=right+len;
                continue;
            }

            mp[word]++;
            cnt++;

            // 当前单词出现次数过多，收缩窗口
            while(mp[word]>need[word]){
                string temp=s.substr(left,len);
                mp[temp]--;
                cnt--;
                left+=len;
            }

            // 找到包含全部单词的合法窗口
            if(cnt==m){
                ans.push_back(left);

                // 左边界右移，继续寻找
                string temp=s.substr(left,len);
                mp[temp]--;
                cnt--;
                left+=len;
            }
        }
    }

    return ans;
}