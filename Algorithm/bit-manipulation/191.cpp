// 位1的个数
// n&(n-1)表示去掉最后一位的1,n&1表示最后一位是否是1
#include <iostream>
using namespace std;

int hammingWeight(int n) {
    uint32_t x = static_cast<uint32_t>(n);
    int count = 0;

    while (x != 0) {
        count += (x & 1);  // 判断最低位是否为1
        x >>= 1;           // 右移一位
    }

    return count;
}