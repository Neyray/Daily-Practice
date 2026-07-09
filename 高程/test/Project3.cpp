/*【问题描述】

小明发明了一种新的字符串加密方法，该方法是统计每一个字符出现的频率，并按照频率从小到大进行排序。假设共有已经按照频率排好序的M个字
符code，然后将字符code[i]和code[m-i]进行交换，只交换一次。如果输入的字母种类是奇数个，那么频率是中间的字母不加密。

【输入形式】

一行字符串，每一个字符出现的频率不一样。

【输出形式】

输出加密后的字符串

【样例输入】


ABCDBDCDBCCDD

【样例输出】


DCBACABACBBAA

【样例说明】

每一个字符出现的频率是A=1，B=3，C=4，D=5

那么就是将A和D交换，B和C交换，加密后的字符串是

DCBACABACBBAA

【评分标准】
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 结构体用于存储字符和其频率
struct CharFreq {
    char ch;
    int freq;

    // 重载小于运算符，用于按频率排序
    //让sort函数知道怎么排序
    bool operator<(const CharFreq& other) const {
        return freq < other.freq;
    }
};

int main() {
    string input;
    cin >> input;

    // 统计字符频率
    map<char, int> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }

    // 将频率信息存入向量
    vector<CharFreq> charFreqs;
    for (auto& pair : freqMap) {
        charFreqs.push_back({ pair.first, pair.second });
    }

    // 按频率排序
    sort(charFreqs.begin(), charFreqs.end());

    int m = charFreqs.size();

    //我就是这一步没想出来
    // 创建字符映射表
    map<char, char> charMap;

    // 建立加密映射关系
    for (int i = 0; i < m / 2; i++) {
        charMap[charFreqs[i].ch] = charFreqs[m - 1 - i].ch;
        charMap[charFreqs[m - 1 - i].ch] = charFreqs[i].ch;
    }

    // 如果字符种类是奇数，中间字符映射到自己
    if (m % 2 == 1) {
        charMap[charFreqs[m / 2].ch] = charFreqs[m / 2].ch;
    }

    // 加密字符串
    string result;
    for (char c : input) {
        result += charMap[c];
    }

    cout << result << endl;

    return 0;
}