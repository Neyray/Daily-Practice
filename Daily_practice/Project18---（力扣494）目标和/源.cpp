#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    /* 如果目标值的绝对值大于数组总和，或者(sum + target) 是奇数，直接返回 0*/
    if (target > sum || (sum + target) % 2 != 0 || (sum + target) < 0) return 0;

    // 计算目标子集和 P = (sum + target) / 2
    int P = (sum + target) / 2;

    // 创建 dp 数组，dp[i] 表示和为 i 的子集的数量
    vector<int> dp(P + 1, 0);
    dp[0] = 1; // 和为0的子集只有一个，就是不选择任何元素

    // 遍历每个数字，更新 dp 数组
    for (int num : nums) {
        for (int i = P; i >= num; --i) {
            dp[i] += dp[i - num];
        }
    }

    // 返回和为 P 的子集数
    return dp[P];
}

int main() {
    vector<int> nums1 = { 1, 1, 1, 1, 1 };
    int target1 = 3;
    cout << "示例1的结果: " << findTargetSumWays(nums1, target1) << endl;

    vector<int> nums2 = { 1, 5, 11, 5 };
    int target2 = 3;
    cout << "示例2的结果: " << findTargetSumWays(nums2, target2) << endl;

    return 0;
}
