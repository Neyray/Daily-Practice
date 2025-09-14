#include <iostream>
#include <vector>
using namespace std;

// 二分查找函数：返回目标值的索引，若不存在，返回插入位置
int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出

        if (nums[mid] == target) {
            return mid;  // 找到目标值，返回其索引
        }
        else if (nums[mid] < target) {
            left = mid + 1;  // 目标值在右侧
        }
        else {
            right = mid - 1;  // 目标值在左侧
        }
    }

    // 目标值不存在，返回它的插入位置
    return left;
}

int main() {
    // 示例数组和目标值
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 5;

    // 调用函数
    int result = searchInsert(nums, target);

    // 输出结果
    cout << "目标值 " << target << " 的位置是: " << result << endl;

    // 测试目标值不存在的情况
    target = 2;
    result = searchInsert(nums, target);
    cout << "目标值 " << target << " 应该插入的位置是: " << result << endl;

    return 0;
}
