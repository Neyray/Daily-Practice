#include <iostream>
#include <vector>
using namespace std;

// 二分查找函数
int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出

        if (nums[mid] == target) {
            return mid;  // 找到目标，返回下标
        }
        else if (nums[mid] < target) {
            left = mid + 1;  // 目标在右侧
        }
        else {
            right = mid - 1;  // 目标在左侧
        }
    }

    return -1;  // 目标不存在
}

int main() {
    // 示例数组和目标值
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;

    // 调用二分查找函数
    int result = binarySearch(nums, target);

    // 输出结果
    if (result != -1) {
        cout << "目标值 " << target << " 的下标是: " << result << endl;
    }
    else {
        cout << "目标值 " << target << " 不存在于数组中。" << endl;
    }

    return 0;
}
