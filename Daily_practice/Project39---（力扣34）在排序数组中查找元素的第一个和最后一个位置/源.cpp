#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);  // 默认返回 [-1, -1]

    // 查找左边界（开始位置）
    int left = 0, right = nums.size() - 1;
    int start = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            start = mid;
            right = mid - 1;  // 继续向左查找
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // 如果没有找到目标值，直接返回 [-1, -1]
    if (start == -1) {
        return result;
    }

    // 查找右边界（结束位置）
    left = start;  // 从左边界开始
    right = nums.size() - 1;
    int end = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            end = mid;
            left = mid + 1;  // 继续向右查找
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // 返回开始和结束位置
    result[0] = start;
    result[1] = end;
    return result;
}

int main() {
    // 示例1
    vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
    int target1 = 8;
    vector<int> result1 = searchRange(nums1, target1);
    cout << "结果: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // 示例2
    vector<int> nums2 = { 5, 7, 7, 8, 8, 10 };
    int target2 = 6;
    vector<int> result2 = searchRange(nums2, target2);
    cout << "结果: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // 示例3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = searchRange(nums3, target3);
    cout << "结果: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
