/*某国导弹拦截系统每次只能拦截不高于前一发高度的导弹。给定导弹依次飞来的高度，求最少需要多少套拦截系统。
*/
//必须严格递减，本质上是求最长递增子序列问题
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 使用二分查找来优化拦截系统的选择
int minInterceptSystems(vector<int>& missiles) {
    vector<int> systems;  // 存储每个拦截系统能拦截的最大高度

    for (int height : missiles) {
        // 查找当前导弹的高度应该放在哪个系统中
        auto it = lower_bound(systems.begin(), systems.end(), height);//寻找第一个大于等于height的值
        //height大于该高度值
        if (it == systems.end()) {
            // 如果没有找到合适的系统，添加新的系统
            systems.push_back(height);
        }
        else {
            // 如果找到了合适的系统，更新该系统的最大拦截高度
            *it = height;
        }
    }

    return systems.size();  // 返回拦截系统的数量
}

int main() {
    vector<int> missiles = { 5, 3, 7, 4, 6, 8, 2, 3 };  // 示例输入
    cout << "最少需要的拦截系统数量是: " << minInterceptSystems(missiles) << endl;
    return 0;
}
