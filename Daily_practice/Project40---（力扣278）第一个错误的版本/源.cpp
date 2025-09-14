#include <iostream>
using namespace std;

// 假设 isBadVersion 是 API 给定的接口
// 你不需要实现它，这里只是一个模拟
bool isBadVersion(int version) {
    // 假设 bad 是已知的错误版本
    const int bad = 4;  // 这里设定 bad 版本为 4
    return version >= bad;
}

int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            right = mid;  // mid 可能是错误版本或更早的版本
        }
        else {
            left = mid + 1;  // 错误版本在 mid + 1 之后
        }
    }

    // 当 left == right 时，找到第一个错误的版本
    return left;
}

int main() {
    int n = 5;
    int result = firstBadVersion(n);
    cout << "第一个错误的版本是: " << result << endl;

    return 0;
}
