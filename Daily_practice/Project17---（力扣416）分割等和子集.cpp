#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    // 如果总和是奇数，不可能分割成两个相等的子集
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // 和为0时，表示可以通过不选任何元素来达成

    // 遍历数组中的每个元素
    for (int num : nums) {
        // 从后往前更新 dp 数组，防止重复使用同一个元素
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // 如果 dp[target] 为 true，说明能够找到一个子集，和为 target
    return dp[target];
}

int main() {
    vector<int> nums1 = { 1, 5, 11, 5 };
    vector<int> nums2 = { 2,3,6,5,2,4 };

    cout << "示例1: " << (canPartition(nums1) ? "true" : "false") << endl;
    cout << "示例2: " << (canPartition(nums2) ? "true" : "false") << endl;

    return 0;
}
