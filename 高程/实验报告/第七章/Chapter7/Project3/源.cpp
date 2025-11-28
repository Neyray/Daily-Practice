#include<iostream>
using namespace std;

class Base {
public:
    //Base() { a = 0; }  // 注释掉了默认构造函数
    Base(int i) { a = i; }
protected:
    int a;
};

/*
class Derived : public Base {
public:
    // 这里会出错，因为Derived()试图调用Base()，但Base()不存在
    Derived() { b = 0; }  // 错误：没有合适的默认构造函数可用
    Derived(int i) { b = i; }  // 错误：需要显式调用基类构造函数
    void Print() { cout << "a=" << a << ", b=" << b << endl; }
private:
    int b;
};
*/

// 修正版本：
class DerivedFixed : public Base {
public:
    DerivedFixed() : Base(0) { b = 0; }  // 正确：显式调用基类构造函数
    DerivedFixed(int i) : Base(i) { b = i; }  // 正确：显式调用基类构造函数
    void Print() { cout << "a=" << a << ", b=" << b << endl; }
private:
    int b;
};

int main() {
    // Derived d1;  // 这行会编译错误
    // Derived d2(12);  // 这行也会编译错误

    DerivedFixed d1;
    DerivedFixed d2(12);
    d1.Print();
    d2.Print();
    cin.ignore();
    return 0;
}