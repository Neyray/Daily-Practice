//根据输入来求出位数为n的小写字母的排列种数，相同字母的连续不能超过3个

/*错误的写法，运行时间过长
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//计算减去的种数,n表示位数
long long function(long long n) {
    long long result = 0;
    if (n <= 3) {
        return 1;
    }
    else {
        for (long long l = 4; l <= n; ++l) {
            long long sum = 26 * (n - l + 1) * function(n - l);
            result += sum;
        }
    }
    return result;
}

int main() {
    //处理输入
    long long n;
    cin >> n;
    cin.ignore();

    long long a;
    cin >> a;
    cin.ignore();

    long long b;
    cin >> b;

    //进行计算
    long long ans1 = 0, ans2 = 0;
    if (a <= 3) {
        ans1 = pow(26, a);
    }
    else {
        ans1 = pow(26, a) - function(a);
    }


    if (b <= 3) {
        ans2 = pow(26, b);
    }
    else {
        ans2 = pow(26, b) - function(b);
    }

    int num = pow(10, 9) + 7;
    ans1 = ans1 % num;
    ans2 = ans2 % num;

    printf("%lld", ans1);
    cout << endl;
    printf("%lld", ans1);

    return 0;
}*/

//正确的写法，采用动态规划
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

// 动态规划解决：计算长度为n的不含连续3个相同字母的字符串数量
long long countValidStrings(int n) {
    if (n == 0) return 0;
    if (n == 1) return 26;
    if (n == 2) return 26 * 26;
    
    // dp[i][j] 表示长度为i，最后有j个连续相同字母的字符串数量
    // j=1: 最后1个字母与前面不同
    // j=2: 最后2个字母相同
    vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
    
    // 初始化
    dp[1][1] = 26;  // 长度为1，所有26个字母都满足
    dp[1][2] = 0;   // 长度为1，不可能有2个连续
    
    for (int i = 2; i <= n; i++) {
        // 当前字符与上一个字符不同：可以从任意状态转移过来
        dp[i][1] = (dp[i-1][1] * 25 + dp[i-1][2] * 25) % MOD;
        
        // 当前字符与上一个字符相同：只能从最后1个字符不同的状态转移过来
        dp[i][2] = dp[i-1][1] % MOD;
    }
    
    // 总数量 = 所有状态的和
    return (dp[n][1] + dp[n][2]) % MOD;
}

// 更简洁的DP版本
long long countValidStrings2(int n) {
    if (n == 0) return 0;
    if (n == 1) return 26;
    if (n == 2) return 26 * 26;
    
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // 空字符串
    dp[1] = 26;
    dp[2] = 26 * 26;
    
    for (int i = 3; i <= n; i++) {
        // 状态转移：当前字符可以：
        // 1. 与前一个字符不同：dp[i-1] * 25
        // 2. 与前一个字符相同，但与前两个字符不同：dp[i-2] * 25  
        dp[i] = (dp[i-1] * 25 + dp[i-2] * 25) % MOD;
    }
    
    return dp[n];
}

// 优化空间的DP版本
long long countValidStrings3(int n) {
    if (n == 0) return 0;
    if (n == 1) return 26;
    if (n == 2) return 26 * 26;
    
    long long a = 1;      // dp[0]
    long long b = 26;     // dp[1]
    long long c = 26 * 26; // dp[2]
    
    for (int i = 3; i <= n; i++) {
        long long next = (c * 25 + b * 25) % MOD;
        a = b;
        b = c;
        c = next;
    }
    
    return c;
}

int main() {
    long long n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    
    long long ans1 = countValidStrings3(a);
    long long ans2 = countValidStrings3(b);
    
    cout << ans1 << endl;
    cout << ans2 << endl;
    
    return 0;
}