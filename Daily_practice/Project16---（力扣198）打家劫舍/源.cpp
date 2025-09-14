#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int>dp(n, 0);
    //一定要注意前两项的定义初始化！
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int main() {
    vector<int> nums;
    int n, val;
    cout << "请输入房屋数量: ";
    cin >> n;
    cout << "请输入每间房屋的金额：";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    cout << "一夜之内能够偷到的最高金额是: " << rob(nums) << endl;

    return 0;
}
