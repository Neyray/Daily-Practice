#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 找零钱 - 贪心算法
class CoinChange {
public:
    // 方法1：固定面额（1, 5, 10, 25, 50, 100）
    static vector<int> makeChange(int amount) {
        int coins[] = { 100, 50, 25, 10, 5, 1 };  // 从大到小
        vector<int> result;

        for (int i = 0; i < 6; i++) {
            while (amount >= coins[i]) {
                result.push_back(coins[i]);
                amount -= coins[i];
            }
        }

        return result;
    }

    // 方法2：返回每种硬币的数量
    static void makeChangeCount(int amount) {
        int coins[] = { 100, 50, 25, 10, 5, 1 };
        string names[] = { "1元", "5角", "2角5分", "1角", "5分", "1分" };

        cout << "找零 " << amount << " 分，需要：" << endl;

        for (int i = 0; i < 6; i++) {
            int count = amount / coins[i];
            if (count > 0) {
                cout << names[i] << ": " << count << " 个" << endl;
                amount %= coins[i];
            }
        }
    }

    // 方法3：自定义面额数组
    static int minCoins(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), greater<int>());  // 降序

        int count = 0;
        for (int coin : coins) {
            count += amount / coin;
            amount %= coin;
        }

        return (amount == 0) ? count : -1;  // 如果无法凑成返回-1
    }
};

int main() {
    cout << "=== 找零钱问题 ===" << endl;

    // 测试1
    vector<int> result = CoinChange::makeChange(137);
    cout << "找零137分，需要硬币：";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
    cout << "总共 " << result.size() << " 个硬币" << endl;

    cout << "\n";

    // 测试2
    CoinChange::makeChangeCount(137);

    cout << "\n";

    // 测试3：自定义面额
    vector<int> coins = { 1, 5, 10, 25 };
    int amount = 63;
    int minCount = CoinChange::minCoins(amount, coins);
    cout << "用 {1,5,10,25} 凑成 " << amount
        << "，最少需要 " << minCount << " 个硬币" << endl;

    return 0;

}