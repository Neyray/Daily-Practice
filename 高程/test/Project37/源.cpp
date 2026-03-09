#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TwoSum {
public:
    // 方法1：有序数组的双指针法
    static vector<int> twoSumSorted(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return { left, right };  // 返回索引
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return { -1, -1 };  // 未找到
    }

    // 方法2：找出所有两数之和等于target的组合
    static vector<pair<int, int>> findAllPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> result;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                result.push_back({ nums[left], nums[right] });

                // 跳过重复元素
                int leftVal = nums[left];
                int rightVal = nums[right];
                while (left < right && nums[left] == leftVal) left++;
                while (left < right && nums[right] == rightVal) right--;

            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return result;
    }

    // 方法3：三数之和（扩展）
    static vector<vector<int>> threeSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            int newTarget = target - nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == newTarget) {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 跳过重复
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;

                }
                else if (sum < newTarget) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    cout << "=== 两数之和问题 ===" << endl;

    // 测试1：有序数组
    vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    vector<int> result1 = TwoSum::twoSumSorted(nums1, target1);
    cout << "数组: 2 7 11 15, 目标: " << target1 << endl;
    cout << "索引: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // 测试2：找所有配对
    cout << "\n=== 找所有配对 ===" << endl;
    vector<int> nums2 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int target2 = 9;
    vector<pair<int, int>> pairs = TwoSum::findAllPairs(nums2, target2);
    cout << "数组: 1 2 3 4 5 6 7 8, 目标: " << target2 << endl;
    cout << "配对: ";
    for (auto p : pairs) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    // 测试3：三数之和
    cout << "\n=== 三数之和 ===" << endl;
    vector<int> nums3 = { -1, 0, 1, 2, -1, -4 };
    int target3 = 0;
    vector<vector<int>> triplets = TwoSum::threeSum(nums3, target3);
    cout << "数组: -1 0 1 2 -1 -4, 目标: " << target3 << endl;
    cout << "三元组: " << endl;
    for (auto t : triplets) {
        cout << "[" << t[0] << ", " << t[1] << ", " << t[2] << "]" << endl;
    }

    return 0;
}