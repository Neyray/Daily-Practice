#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int countCows(int n) {
    // dp数组，记录每年母牛的数量
    vector<int> dp(n + 1, 0);

    // 初始条件
    dp[1] = 1; // 第1年1头母牛
    if (n > 1) dp[2] = 2; // 第2年2头母牛
    if (n > 2) dp[3] = 3; // 第3年3头母牛

    // 从第4年开始，按照递推关系计算
    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 3]; // dp[i-1]是上一年的母牛数，dp[i-3]是开始生育的小母牛数
    }

    return dp[n];
}

int main() {
    ifstream inFiles("in.txt");  // 从文件读取数据
    if (!inFiles) {
        cerr << "error!" << endl;
        return -1;
    }

    int n;
    inFiles >> n;  // 读取n的值
    cout << countCows(n);  // 输出第n年的母牛数量
    return 0;
}
