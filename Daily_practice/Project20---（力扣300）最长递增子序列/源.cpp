#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] 表示以 nums[i] 为结尾的最长递增子序列的长度

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 返回 dp 数组中的最大值，即为最长递增子序列的长度
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums1 = { 10, 9, 2, 5, 3, 7, 101, 18 };
    cout << "示例1的结果: " << lengthOfLIS(nums1) << endl; // 输出 4

    vector<int> nums2 = { 0, 1, 0, 3, 2, 3 };
    cout << "示例2的结果: " << lengthOfLIS(nums2) << endl; // 输出 4

    vector<int> nums3 = { 7, 7, 7, 7, 7, 7 };
    cout << "示例3的结果: " << lengthOfLIS(nums3) << endl; // 输出 1

    return 0;
}
