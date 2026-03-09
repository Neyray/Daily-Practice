#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int current_water = min(height[left], height[right]) * (right - left);
        max_water = max(max_water, current_water);

        if (height[left] < height[right]) {
            ++left;
        }
        else {
            --right;
        }
    }

    return max_water;
}

int main() {
    // 示例1
    vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << "示例1的最大水量: " << maxArea(height1) << endl; // 输出 49

    // 示例2
    vector<int> height2 = { 1, 1 };
    cout << "示例2的最大水量: " << maxArea(height2) << endl; // 输出 1

    // 示例3
    vector<int> height3 = { 4, 3, 2, 1, 4 };
    cout << "示例3的最大水量: " << maxArea(height3) << endl; // 输出 16

    // 示例4
    vector<int> height4 = { 1, 2, 1 };
    cout << "示例4的最大水量: " << maxArea(height4) << endl; // 输出 2

    return 0;
}
