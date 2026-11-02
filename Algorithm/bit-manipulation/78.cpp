// 子集
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    // 枚举所有二进制状态，实际上就是在枚举所有子集，再根据这个把数组元素加入path，存入ans
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> path;

        // 判断每一位是否为1
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                path.push_back(nums[j]);
            }
        }

        ans.push_back(path);
    }

    return ans;
}