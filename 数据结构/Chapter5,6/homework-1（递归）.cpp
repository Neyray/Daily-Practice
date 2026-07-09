#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 递归函数来处理n进制转换
void convertToBase(int num, int n, vector<int>& result) {
    if (num == 0) {
        return;  // 基本情况，当num为0时停止递归
    }

    // 递归计算num的下一位
    convertToBase(num / n, n, result);

    // 计算当前位
    result.push_back(num % n);
}

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

    // 特殊情况：如果num是0，直接处理
    if (num == 0) {
        result.push_back(0);
    }
    else {
        // 调用递归函数
        convertToBase(num, n, result);
    }

    // 输出到out.txt
    ofstream outFiles("out.txt");
    if (!outFiles) {
        cerr << "error!" << endl;
        return -1;
    }

    // 输出每一位，中间用空格隔开
    for (int i = 0; i < result.size(); ++i) {
        outFiles << result[i] << " ";
    }

    return 0;
}
