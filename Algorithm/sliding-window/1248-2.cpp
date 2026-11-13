#include <iostream>
#include <vector>
using namespace std;


int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();

    // 统计奇数个数至多为limit的子数组
    auto atMost=[&](int limit){
        int left=0,odd=0,ans=0;

        for(int right=0;right<n;++right){
            odd+=nums[right]%2;

            while(odd>limit){
                odd-=nums[left]%2;
                left++;
            }

            ans+=right-left+1;
        }

        return ans;
    };

    return atMost(k)-atMost(k-1);
}