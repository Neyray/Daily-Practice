#include <iostream>
using namespace std;

class CPU {
public:
    CPU(unsigned int freq, unsigned int bits, unsigned int cores, bool ht)
        : frequency(freq), wordLength(bits), coreCount(cores), hyperThreading(ht) {
    }

    void show() const {
        cout << "CPU信息：" << endl;
        cout << "  主频: " << frequency << " MHz" << endl;
        cout << "  字长: " << wordLength << " 位" << endl;
        cout << "  核心数: " << coreCount << endl;
        cout << "  是否支持超线程: " << (hyperThreading ? "是" : "否") << endl;
    }

private:
    //表示所占的位域，也就是二进制位
    unsigned int frequency : 12;     // 支持到 4095 MHz
    unsigned int wordLength : 6;     // 32或64
    unsigned int coreCount : 4;      // 单核/双核/四核
    bool hyperThreading : 1;         // 是否超线程
};

int main() {
    CPU cpu1(2800, 64, 4, true);
    cpu1.show();
    cout << "sizeof(CPU) = " << sizeof(CPU) << " 字节" << endl;
    return 0;
}
