// 删除有序数组中的重复项 II
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int n = nums.size();
    int slow = 0;
    int count = 1;

    for (int fast = 1; fast < n; ++fast) {
        if (nums[fast] == nums[slow]) {
            count++;
            if (count <= 2) {
                nums[++slow] = nums[fast];
            }
        } else {
            count = 1;
            nums[++slow] = nums[fast];
        }
    }

    return slow + 1;
}