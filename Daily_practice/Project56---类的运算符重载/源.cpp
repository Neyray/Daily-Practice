#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 重载运算符 +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 重载运算符 <<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << "i)";
        return os;
    }

    // 重载运算符 ==
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);

    // 测试加法运算符重载
    Complex c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    // 测试输出运算符重载
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    // 测试相等运算符重载
    Complex c4(4.5, 6.5);
    if (c3 == c4) {
        std::cout << "c3 is equal to c4" << std::endl;
    }
    else {
        std::cout << "c3 is not equal to c4" << std::endl;
    }

    return 0;
}
