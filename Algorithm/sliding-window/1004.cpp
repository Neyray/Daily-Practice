// 最大连续 1 的个数 III
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int left = 0;
    int zero = 0;
    int ans = 0;

    for (int right = 0; right < n; ++right) {
        // 扩大窗口，统计 0 的数量

        // right只管向前扩展滑动窗口，left来兜底
        if (nums[right] == 0) {
            zero++;
        }

        // 0 的数量超过 k，窗口不合法
        while (zero > k) {
            if (nums[left] == 0) {
                zero--;
            }
            left++;
        }

        // 窗口合法，更新最长长度
        ans = max(ans, right - left + 1);
    }

    return ans;
}