#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // 关键逻辑：判断 mid 和 right 之间的大小关系
        if (nums[mid] > nums[right]) {
            left = mid + 1;  // 最小值在右侧
        }
        else {
            right = mid;  // 最小值在 mid 或者 mid 左侧
        }
    }

    return nums[left];  // left 最终会指向最小元素
}

int main() {
    vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 };
    vector<int> nums2 = { 3, 4, 5, 1, 2 };
    vector<int> nums3 = { 11, 13, 15, 17 };

    cout << "最小元素: " << findMin(nums1) << endl;  // 输出 0
    cout << "最小元素: " << findMin(nums2) << endl;  // 输出 1
    cout << "最小元素: " << findMin(nums3) << endl;  // 输出 11

    return 0;
}
