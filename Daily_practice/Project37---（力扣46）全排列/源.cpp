#include <iostream>
#include <vector>
using namespace std;

// 回溯算法：生成所有排列
void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
    // 如果当前排列的长度等于 nums 的长度，则找到一个完整的排列
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    // 遍历 nums 数组中的每个数字
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;  // 如果该数字已经被使用过，跳过

        // 选择当前数字
        used[i] = true;
        current.push_back(nums[i]);

        // 递归生成下一个数字
        backtrack(nums, current, result, used);

        // 回溯，撤销选择
        used[i] = false;
        current.pop_back();
    }
}

// 主函数：调用回溯算法生成所有排列
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;  // 存储结果
    vector<int> current;  // 存储当前排列
    vector<bool> used(nums.size(), false);  // 标记元素是否被使用

    backtrack(nums, current, result, used);

    return result;
}

int main() {
    // 示例输入
    vector<int> nums = { 1, 2, 3 };

    // 获取所有全排列
    vector<vector<int>> result = permute(nums);

    // 输出结果
    cout << "所有全排列如下：" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
