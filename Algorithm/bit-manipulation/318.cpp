// 最大单词长度乘积
// | 用于合并元素，& 用于检查共同元素，^ 用于判断哪些位不同
#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int maxProduct(vector<string>& words) {
    int n = words.size();

    function<bool(const string&, const string&)> compare =
        [&](const string& word1, const string& word2) {
            uint32_t num1 = 0;
            uint32_t num2 = 0;

            for (int i = 0; i < word1.length(); ++i) {
                int num = word1[i] - 'a';
                num1 |= 1u << num;
            }

            for (int j = 0; j < word2.length(); ++j) {
                int num = word2[j] - 'a';
                num2 |= 1u << num;
            }

            return (num1 & num2) == 0;
        };

    int result = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (compare(words[i], words[j])) {
                int count = words[i].length() * words[j].length();
                result = max(result, count);
            }
        }
    }

    return result;
}