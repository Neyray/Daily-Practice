// 划分字母区间
// 贪心：每次尽可能早地结束当前片段，从而让后面可以划分出更多片段
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);

    for (int i = 0; i < s.size(); ++i) {
        last[s[i] - 'a'] = i;
    }

    vector<int> ans;
    int start = 0;
    int end = 0;

    for (int i = 0; i < s.size(); ++i) {
        end = max(end, last[s[i] - 'a']);

        if (i == end) {
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return ans;
}