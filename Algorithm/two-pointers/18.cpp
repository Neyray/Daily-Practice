// 四数之和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;

    int n=nums.size();
    if(n<4)return {};

    sort(nums.begin(),nums.end());

    for(int i=0;i<n-3;++i){
        // 第一层去重
        if(i>0 && nums[i]==nums[i-1])continue;

        for(int j=i+1;j<n-2;++j){
            // 第二层去重
            if(j>i+1 && nums[j]==nums[j-1])continue;

            int p1=j+1,p2=n-1;

            while(p1<p2){
                long long sum=1LL*nums[i]+nums[j]+nums[p1]+nums[p2];

                if(sum<target){
                    p1++;
                }else if(sum>target){
                    p2--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[p1],nums[p2]});

                    // 左指针去重
                    while(p1<p2 && nums[p1]==nums[p1+1]){
                        p1++;
                    }

                    // 右指针去重
                    while(p1<p2 && nums[p2]==nums[p2-1]){
                        p2--;
                    }

                    p1++;
                    p2--;
                }
            }
        }
    }

    return ans;
}