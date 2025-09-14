#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    // 初始化最大值和最小值
    int max_prod = nums[0], min_prod = nums[0], result = nums[0];

    // 从第二个元素开始遍历
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            // 负数时交换最大值和最小值，因为负数可能变成最大值
            swap(max_prod, min_prod);
        }

        // 更新最大值和最小值
        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);

        // 更新最终的结果
        result = max(result, max_prod);
    }

    return result;
}

int main() {
    vector<int> nums1 = { 2, 3, -2, 4 };
    cout << "示例1的结果: " << maxProduct(nums1) << endl;  // 输出 6

    vector<int> nums2 = { -2, 0, -1 };
    cout << "示例2的结果: " << maxProduct(nums2) << endl;  // 输出 0

    return 0;
}
