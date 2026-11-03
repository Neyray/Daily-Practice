#include <iostream>
#include <vector>
using namespace std;


// LeetCode 3736：最小操作次数使数组元素相等 III
// 数学 + 贪心
// 时间复杂度 O(n)，空间复杂度 O(1)

int minMoves(vector<int>& nums) {
    int mx = 0, sum = 0;

    for (int x : nums) {
        mx = max(mx, x);
        sum += x;
    }

    return mx * nums.size() - sum;
}