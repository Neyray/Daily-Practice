// 三数之和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 15：三数之和
// 排序 + 双指针 + 去重
// 时间复杂度 O(n²)

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; ++i) {
        // 第一个数去重
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        if (nums[i] > 0) break;

        int p1 = i + 1, p2 = n - 1;

        while (p1 < p2) {
            int sum = nums[i] + nums[p1] + nums[p2];

            if (sum < 0) {
                p1++;
            } else if (sum > 0) {
                p2--;
            } else {
                ans.push_back({nums[i], nums[p1], nums[p2]});

                // 第二个数去重
                while (p1 < p2 && nums[p1] == nums[p1 + 1]) {
                    p1++;
                }

                // 第三个数去重
                while (p1 < p2 && nums[p2] == nums[p2 - 1]) {
                    p2--;
                }
                // 此时p1,p2都是各自重复数字的最后一位，所以之后还要进行更新操作

                p1++;
                p2--;
            }
        }
    }

    return ans;
}