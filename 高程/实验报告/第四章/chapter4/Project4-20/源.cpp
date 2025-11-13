#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    void add(const Complex& c) {
        real += c.real;
        imag += c.imag;
    }
    void show() const {
        cout << real << "+" << imag << "i" << endl;
    }

private:
    double real;
    double imag;//i前面的系数
};

int main() {
    Complex c1(3, 5);    // 用复数初始化
    Complex c2 = 4.5;   // 用实数初始化（隐式转换）
    c1.add(c2);         // 相加
    c1.show();          
    return 0;
}
