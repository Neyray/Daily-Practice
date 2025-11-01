#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (i % 2 == 0) {
            // 在偶数位置，确保 nums[i] < nums[i+1]
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
        else {
            // 在奇数位置，确保 nums[i] > nums[i+1]
            if (nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
}

int main() {
    vector<int> nums1 = { 3, 5, 2, 1, 6, 4 };
    wiggleSort(nums1);
    cout << "重新排列后的数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 3 5 1 6 2 4

    vector<int> nums2 = { 1, 2, 3, 4, 5 };
    wiggleSort(nums2);
    cout << "重新排列后的数组: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;  // 输出: 1 3 2 5 4

    return 0;
}
