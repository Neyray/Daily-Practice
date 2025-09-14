#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream inFiles("in.txt");
    if (!inFiles) {
        cerr << "error!" << endl;
        return -1;
    }

    // 输入数字m和进制n
    int num, n;
    inFiles >> num >> n;

    vector<int> result;

    // 将数字转换为n进制
    while (num > 0) {
        result.push_back(num % n);  // 余数作为当前位
        num = num / n;  // 更新num为除以n后的值
    }

    // 由于我们是从低位到高位存储，结果需要反转
    int size = result.size();
    for (int i = 0; i < (size / 2); ++i) {
        swap(result[i], result[size - i - 1]);
    }

    // 输出到out.txt
    ofstream outFiles("out.txt");
    if (!outFiles) {
        cerr << "error!" << endl;
        return -1;
    }

    // 输出每一位，中间用空格隔开
    for (int i = 0; i < size; ++i) {
        outFiles << result[i] << " ";
    }

    return 0;
}
