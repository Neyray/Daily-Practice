// 只出现一次的数字
// 别的数字出现两次
// ^ 异或运算可以交换、结合
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int x : nums) {
        ans ^= x;  // 相同数字异或后抵消
    }

    return ans;
}