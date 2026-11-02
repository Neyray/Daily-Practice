// 删除有序数组中的重复项 II
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int slow = 0;

    for (int fast = 0; fast < nums.size(); ++fast) {
        if (slow < 2 || nums[fast] != nums[slow - 2]) {
            nums[slow++] = nums[fast];
        }
    }

    return slow;
}