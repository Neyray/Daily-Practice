// 乘积小于 K 的子数组
#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k<=1)return 0;

    int n=nums.size();
    int left=0;
    int ans=0;
    int temp=1;

    for(int right=0;right<n;++right){
        temp*=nums[right];

        while(temp>=k){
            temp/=nums[left];
            left++;
        }

        // 为什么在这里更新？因为right变化了位置，加入了前面的判断条件后再统计增加的子数组数量
        ans+=right-left+1;
    }

    return ans;
}