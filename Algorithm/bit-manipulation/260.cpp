// 只出现一次的数字 III
// 两个元素出现一次，其余元素出现两次
// x&(-x)表示保留最后一位的1，其余的都设为0，可用来对异或后的数据进行分组；-x=~x+1（无符号数）
#include <iostream>
#include <vector>
using namespace std;



vector<int> singleNumber(vector<int>& nums) {
    uint32_t x = 0;

    // 第一步：全部异或，得到两个不同数字的异或值
    for (int num : nums) {
        x ^= static_cast<uint32_t>(num);
    }

    // 第二步：提取最低位的1，作为分组依据
    uint32_t lowbit = x & -x;

    int a = 0, b = 0;

    // 第三步：按照lowbit分组，分别异或
    for (int num : nums) {
        if (static_cast<uint32_t>(num) & lowbit) {
            a ^= num;
        } else {
            b ^= num;
        }
    }

    return {a, b};
}