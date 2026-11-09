// 寻找重复数
#include <iostream>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;

    // 第一阶段：找到环内相遇点
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // 第二阶段：寻找环入口
    slow = 0;

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}