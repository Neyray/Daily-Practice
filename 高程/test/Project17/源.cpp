//盛水问题
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> left_max(n), right_max(n);

    // 从左到右计算每个位置左边的最大高度
    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // 从右到左计算每个位置右边的最大高度
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // 计算每个位置能接的雨水量
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(left_max[i], right_max[i]) - height[i];
    }

    return water;
}

int main() {
    vector<int> height(12);

    // 读取12个整数
    for (int i = 0; i < 12; i++) {
        cin >> height[i];
    }

    int result = trap(height);
    cout << result << endl;

    return 0;
}