// 计算算术平方根
#include <iostream>
#include <vector>

int mySqrt(int x) {
    int low = 0, high = x;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // 类型转换要在运算发生之前，1LL本身就是long long类型，所以会按long long方式计算
        long long square = 1LL * mid * mid;

        if (square <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}