#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;

    vector<int> candies(n, 1);  // 初始化每个孩子至少一个糖果

    // 从左到右遍历
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // 从右到左遍历
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // 计算总糖果数
    int totalCandies = 0;
    for (int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies;
}

int main() {
    // 示例 1
    vector<int> ratings1 = { 1, 0, 2 };
    cout << "示例1的输出: " << candy(ratings1) << endl;  // 输出 5

    // 示例 2
    vector<int> ratings2 = { 1, 2, 2 };
    cout << "示例2的输出: " << candy(ratings2) << endl;  // 输出 4

    return 0;
}
