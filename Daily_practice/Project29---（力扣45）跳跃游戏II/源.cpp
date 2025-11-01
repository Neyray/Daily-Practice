#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;  // 如果数组只有一个元素或为空，则不需要跳跃

    int jumps = 0;        // 跳跃次数
    int currentEnd = 0;   // 当前跳跃范围的结束位置
    int farthest = 0;     // 当前跳跃能到达的最远位置

    for (int i = 0; i < n; ++i) {
        // 更新最远可到达位置
        farthest = max(farthest, i + nums[i]);

        // 如果到达了当前跳跃范围的结束位置
        if (i == currentEnd) {
            if (i != n - 1) { // 如果没有到达最后一个位置
                jumps++;  // 进行一次跳跃
                currentEnd = farthest;  // 更新当前跳跃范围的结束位置
            }
        }
    }
    return jumps;
}

int main() {
    vector<int> nums1 = { 2, 3, 1, 1, 4 };
    cout << "示例1的输出: " << jump(nums1) << endl;  // 输出 2

    vector<int> nums2 = { 2, 3, 0, 1, 4 };
    cout << "示例2的输出: " << jump(nums2) << endl;  // 输出 2

    return 0;
}
