/*
【问题描述】
定义一个复数类Complex，包含实部real和虚部imag两个属性。
要求通过运算符重载实现以下功能：
- 复数的输入输出(>>, <<)
- 复数的加减乘除运算(+, -, *, /)
- 复数的比较运算(==, !=)，比较模是否相等
- 复数的取反运算(-)

【输入形式】
输入两个复数，每个复数占一行，格式为：实部 虚部

【输出形式】
- 复数输出格式：实部+虚部i（虚部为负时自动显示为实部-虚部i）
- 依次输出以下表达式的结果（每个结果占一行）：
  c1 + c2
  c1 - c2
  c1 * c2
  c1 / c2
  -c1
  c1 == c2
  c1 != c2

【样例输入】
3 4
1 2

【样例输出】
4+6i
2+2i
-5+10i
1.36364+0.545455i
-3-4i
0
1

【样例说明】
输入复数c1=3+4i，c2=1+2i
输出各种运算结果
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 输入运算符
    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    // 输出运算符
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << "+" << c.imag << "i";
        }
        else {
            out << c.imag << "i";
        }
        return out;
    }

    // 加法运算符
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // 减法运算符
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // 乘法运算符
    Complex operator*(const Complex& c) const {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // 除法运算符
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        double r = (real * c.real + imag * c.imag) / denominator;
        double i = (imag * c.real - real * c.imag) / denominator;
        return Complex(r, i);
    }

    // 取反运算符
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // 计算模
    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    // 等于运算符（比较模）
    bool operator==(const Complex& c) const {
        return fabs(modulus() - c.modulus()) < 1e-6;
    }

    // 不等于运算符
    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }
};

int main() {
    Complex c1, c2;
    cin >> c1 >> c2;

    cout << fixed << setprecision(6);
    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 / c2 << endl;
    cout << -c1 << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;

    return 0;
}