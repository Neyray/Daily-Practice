// 水果成篮
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int totalFruit(vector<int>& fruits) {
    int ans = 0;
    int left = 0;

    unordered_map<int, int> mp;

    for (int right = 0; right < fruits.size(); ++right) {
        // 加入右端水果
        // right只管“开疆拓土”
        mp[fruits[right]]++;

        // 水果种类超过 2，缩小窗口
        while (mp.size() > 2) {
            mp[fruits[left]]--;

            // 某种水果已经不存在，删除对应键
            if (mp[fruits[left]] == 0) {
                mp.erase(fruits[left]);
            }

            left++;
        }

        // 当前窗口合法，更新最大长度
        ans = max(ans, right - left + 1);
    }

    return ans;
}