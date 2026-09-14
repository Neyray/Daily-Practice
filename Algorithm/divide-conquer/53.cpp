// 最大子数组和
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int cur = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        cur = max(nums[i], cur + nums[i]);
        ans = max(ans, cur);
    }

    return ans;
}