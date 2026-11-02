// 分割等和子集
// 位运算，也可以用动态规划
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;

    if (sum % 2 != 0) return false;

    int target = sum / 2;

    // 题目约束下 target 最大为10000
    bitset<10001> bits;
    bits[0] = 1;

    for (int num : nums) {
        bits |= (bits << num);
    }

    return bits[target];
}