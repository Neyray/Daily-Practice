// 最大单词长度乘积
// | 用于合并元素，& 用于检查共同元素，^ 用于判断哪些位不同
#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<uint32_t> mask(n, 0);

    // 每个单词只遍历一次
    for (int i = 0; i < n; ++i) {
        for (char c : words[i]) {
            mask[i] |= 1u << (c - 'a');
        }
    }

    int result = 0;

    // 直接比较已经计算好的位掩码
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((mask[i] & mask[j]) == 0) {
                int count = words[i].length() * words[j].length();
                result = max(result, count);
            }
        }
    }

    return result;
}