// 统计优美子数组
#include <iostream>
#include <vector>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();

    if(k>n)return 0;

    int ans=0;
    int odd=0;
    int left=0;

    for(int right=0;right<n;++right){
        if(nums[right]%2 != 0){
            odd++;
        }

        while(odd>k){
            if(nums[left]%2 != 0){
                odd--;
            }
            left++;
        }

        if(odd==k){
            int temp1=left;
            while(nums[temp1]%2 == 0){
                temp1++;
            }

            ans+=temp1-left+1;
        }
    }

    return ans;
}