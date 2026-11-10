// 长度最小的子数组
// right向右扩展滑动窗口，left依情况右移
// 找最短：满足条件，向右移left，尝试缩小窗口
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; ++right) {
        // 右指针移动，扩大窗口
        sum += nums[right];

        // 满足条件，尝试缩小窗口
        while (sum >= target) {
            ans = min(ans, right - left + 1);

            sum -= nums[left];
            left++;
        }
    }

    return ans == INT_MAX ? 0 : ans;
}