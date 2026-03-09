#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSteal(mid, nums, k)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canSteal(int x, vector<int>& nums, int k) {
        int prev = 0, curr = 0;
        for (int num : nums) {
            int temp = curr;
            if (num <= x) {
                curr = max(curr, prev + 1);
            }
            prev = temp;
        }
        return curr >= k;
    }
};


int main() {
    Solution s1;
    vector<int> nums1 = { 2, 3, 5, 7, 8, 9 };
    int k1 = 2;
    cout << "示例1的最小窃取能力: " << s1.minCapability(nums1, k1) << endl;  // 输出最小窃取能力

    vector<int> nums2 = { 2, 7, 9, 3, 1 };
    int k2 = 2;
    cout << "示例2的最小窃取能力: " << s1.minCapability(nums2, k2) << endl;  // 输出最小窃取能力

    return 0;
}
