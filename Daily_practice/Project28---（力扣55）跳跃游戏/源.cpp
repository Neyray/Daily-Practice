#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;  // 初始化可以到达的最远位置

    for (int i = 0; i < n; ++i) {
        if (i > maxReach) {  // 如果当前位置不可达，返回false
            return false;
        }
        maxReach = max(maxReach, i + nums[i]);  // 更新最远可达位置
        if (maxReach >= n - 1) {  // 如果可以到达最后一个位置
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> nums1 = { 2, 3, 1, 1, 4 };
    cout << "示例1的输出: " << (canJump(nums1) ? "true" : "false") << endl;  // 输出 true

    vector<int> nums2 = { 3, 2, 1, 0, 4 };
    cout << "示例2的输出: " << (canJump(nums2) ? "true" : "false") << endl;  // 输出 false

    return 0;
}
