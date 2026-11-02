// 数字范围按位与
#include <iostream>
#include <vector>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int count = 0;

    // 找到公共二进制前缀
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }

    // 恢复公共前缀的位置
    return left << count;
}