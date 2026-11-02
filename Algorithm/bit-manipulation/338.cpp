// 比特位计数
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);

    function<int(int)> fun = [&](int num) {
        uint32_t x = static_cast<uint32_t>(num);

        int count = 0;
        while (x != 0) {
            if ((x & 1u) == 0) break;

            count++;
            x >>= 1;
        }

        return count - 1;// 表示减少1的数量
    };

    for (int i = 1; i <= n; ++i) {
        int count = fun(i - 1);
        ans[i] = ans[i - 1] - count;
    }

    return ans;
}