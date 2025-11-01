#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止溢出

        // 如果找到目标值，直接返回
        if (nums[mid] == target) {
            return mid;
        }

        // 判断左半部分是否是升序的
        if (nums[left] <= nums[mid]) {
            // 目标值在左半部分
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        // 否则右半部分是升序的
        else {
            // 目标值在右半部分
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    return -1;  // 如果没有找到目标值，返回 -1
}

int main() {
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;

    int result = search(nums, target);
    cout << "目标值 " << target << " 的下标是: " << result << endl;  // 输出 4

    return 0;
}
