// L2 的幂
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    uint32_t x = static_cast<uint32_t>(n);
    int count = 0;

    while (x != 0) {
        count += x & 1;//表示加上x二进制表示的末尾数字
        x >>= 1;
    }

    return count == 1;
}