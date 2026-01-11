#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
    // 基本情况：当current的大小等于nums的大小时，说明一个排列已经完成
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    // 遍历nums数组，尝试每个元素
    for (size_t i = 0; i < nums.size(); ++i) {
        // 如果元素已经被使用过，就跳过
        if (used[i]) continue;

        // 选择当前数字
        used[i] = true;
        current.push_back(nums[i]);

        // 递归生成剩余的排列
        backtrack(nums, current, result, used);

        // 回溯：撤销选择
        used[i] = false;
        current.pop_back();
    }
}

int main() {
    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "error!" << endl;
        return -1;
    }

    vector<int> nums;
    int num;
    while (inFile >> num) {
        nums.push_back(num);
    }

    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);  // 用于标记每个数字是否已被使用

    // 调用回溯函数生成全排列
    backtrack(nums, current, result, used);

    // 输出到控制台
    for (const auto& permutation : result) {
        for (size_t i = 0; i < permutation.size(); ++i) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
