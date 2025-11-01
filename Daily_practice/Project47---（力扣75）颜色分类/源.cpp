#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // 将nums[mid]与nums[low]交换，low和mid都向右移动
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            // nums[mid]已经是1，直接向右移动
            mid++;
        }
        else {
            // nums[mid]是2，交换nums[mid]与nums[high]，high向左移动
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums1 = { 2, 0, 2, 1, 1, 0 };
    sortColors(nums1);
    cout << "排序后的数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 0 0 1 1 2 2

    vector<int> nums2 = { 1, 0 };
    sortColors(nums2);
    cout << "排序后的数组: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 0 1

    return 0;
}
