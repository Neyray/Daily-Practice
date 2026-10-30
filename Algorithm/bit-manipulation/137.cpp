// 只出现一次的数字 II
// 别的数字出现三次
// 核心思想：逐位统计二进制中 1 出现的次数，再对 3 取模
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    uint32_t ans = 0;

    for (int i = 0; i < 32; ++i) {
        int count = 0;

        // 统计所有数字第i位上1的数量
        // 1u表示无符号数的1
        for (int x : nums) {
            count += (static_cast<uint32_t>(x) >> i) & 1u;
        }

        // 对3取模，恢复答案的第i位
        if (count % 3 != 0) {
            ans |= (1u << i);
        }
    }

    return static_cast<int32_t>(ans);
}