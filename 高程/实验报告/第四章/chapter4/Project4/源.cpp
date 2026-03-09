// 析构函数和带默认参数的构造函数。
// 注意构造函数和析构函数的调用顺序。
#include <iostream>
#include <math.h>
using namespace std;

class Complex // 定义复数类
{
public:
    Complex(double r = 0.0, double i = 0.0); // 带默认参数构造函数
    ~Complex();                          // 析构函数
    double abscomplex();                 // 求复数的模

private:
    double real;
    double imag;
};

Complex::Complex(double r, double i)
{
    cout << "constructing..." << endl;
    real = r;
    imag = i;
    cout << "real:" << real << ", imag:" << imag << endl;
}

Complex::~Complex()
{
    cout << "destructing... real:" << real << ", imag:" << imag << endl;
}

double Complex::abscomplex()
{
    double t = real * real + imag * imag;
    return sqrt(t);
}

int main()
{
    Complex A(1.1, 2.2), B = A;
    cout << "abs of complex A=" << A.abscomplex() << endl;
    cout << "abs of complex B=" << B.abscomplex() << endl;
    return 0;
}
