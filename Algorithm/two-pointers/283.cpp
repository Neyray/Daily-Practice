// 移动零
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int slow = -1;


    // 先把非零元素移到前面，再把后面的设为0
    for (int fast = 0; fast < n; ++fast) {
        if (nums[fast] != 0) {
            nums[++slow] = nums[fast];
        }
    }

    for (int i = slow + 1; i < n; ++i) {
        nums[i] = 0;
    }
}