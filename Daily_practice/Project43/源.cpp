/*排序：

先对 position[] 数组进行排序，确保我们可以从最小到最大位置遍历，这样便于计算球之间的间距。

二分查找：

使用 low 和 high 来进行二分查找。low 初始为 1，high 是最远两个篮子之间的距离。
在每次二分查找中，尝试一个中间值 mid，即假设当前最小磁力为 mid，并检查能否放置 m 个球。

贪心策略：

在每次 mid 的尝试中，从第一个篮子开始放置第一个球，然后继续遍历剩余的篮子。每次放置一个球时，确保当前球与上一个球之间的距离至少为 mid。
如果成功放置了 m 个球，则认为当前 mid 是可行的，尝试增大磁力（即调整 low）。如果放置失败，则减少磁力（即调整 high）。

返回结果：

最终，result 保存了可以使得最小磁力最大的值。*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDistance(vector<int>& position, int m) {
    // 排序篮子的位置
    sort(position.begin(), position.end());

    int low = 1;  // 最小的磁力为 1
    int high = position.back() - position.front();  // 最大的磁力为最远两个篮子的距离
    int result = 0;

    // 二分查找最小磁力的最大值
    while (low <= high) {
        int mid = low + (high - low) / 2;  // 中间磁力值

        // 使用贪心方法判断是否能在当前的 mid 磁力下放置 m 个球
        int count = 1;  // 第一个球已经放置在第一个篮子
        int lastPosition = position[0];  // 第一个球的位置

        // 遍历剩余的篮子位置
        for (int i = 1; i < position.size(); i++) {
            // 如果当前篮子和上一个篮子的距离大于等于 mid，放置一个球
            if (position[i] - lastPosition >= mid) {
                count++;  // 放置一个球
                lastPosition = position[i];  // 更新最后一个放置的球的位置
            }

            // 如果已经放置了 m 个球，则成功
            if (count == m) {
                break;
            }
        }

        // 如果可以放置 m 个球，则说明当前 mid 磁力是可行的，尝试更大的磁力
        if (count >= m) {
            result = mid;  // 记录当前可行的最小磁力
            low = mid + 1;  // 尝试更大的磁力
        }
        else {
            high = mid - 1;  // 如果不能放置，则尝试更小的磁力
        }
    }

    return result;  // 返回最大化的最小磁力
}

int main() {
    vector<int> position1 = { 1, 2, 3, 4, 7 };
    int m1 = 3;
    cout << "最大化的最小磁力: " << maxDistance(position1, m1) << endl;  // 输出 3

    vector<int> position2 = { 5, 4, 3, 2, 1, 1000000000 };
    int m2 = 2;
    cout << "最大化的最小磁力: " << maxDistance(position2, m2) << endl;  // 输出 999999999

    return 0;
}
