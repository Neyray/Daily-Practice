#include <iostream>
#include "class.h"
using namespace std;

// X 的成员函数定义
X::X(int v) : i(v) {}

void X::print() const {
    cout << "X.i = " << i << endl;
}

// Y::g 的定义（可以访问 X::i，因为被声明为友元）
void Y::g(X* px) {
    if (px) px->i += 1;
}

// Z::f 的定义（Z 是友元类，所有成员可访问 X 的私有成员）
void Z::f(X* px) {
    if (px) px->i += 5;
}

// 全局友元函数 h
void h(X* px) {
    if (px) px->i += 10;
}
