// 删除有序数组中的重复项
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int slow = 0;

    for (int fast = 1; fast < nums.size(); ++fast) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
    }

    return slow + 1;
}