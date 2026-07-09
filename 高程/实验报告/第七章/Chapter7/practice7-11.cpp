#include <iostream>
using namespace std;

class BaseClass {
protected:
    int a;
    int b;
public:
    virtual int fn1() {
        return a + b;
    }
    virtual int fn2() {
        return a - b;
    }
    BaseClass(int a, int b) : a(a), b(b) {
        cout << "BaseClass构造函数: a=" << a << ", b=" << b << endl;
    }
    virtual ~BaseClass() {
        cout << "BaseClass析构函数" << endl;
    }
};

class DerivedClass : public BaseClass {
private:
    int c;
    int d;
public:
    DerivedClass(int c1, int d1) : BaseClass(c1 + 2, d1 + 2), c(c1), d(d1) {
        cout << "DerivedClass构造函数: c=" << c << ", d=" << d << endl;
    }

    int fn1() override {
        int result = 2 * (c + d) + a + b;
        cout << "DerivedClass::fn1() = 2 * (" << c << " + " << d << ") + " << a << " + " << b
            << " = " << result << endl;
        return result;
    }

    int fn2() override {
        int result = 2 * (c - d) + a - b;
        cout << "DerivedClass::fn2() = 2 * (" << c << " - " << d << ") + " << a << " - " << b
            << " = " << result << endl;
        return result;
    }

    ~DerivedClass() {
        cout << "DerivedClass析构函数" << endl;
    }
};

int main() {
    cout << "=== 创建DerivedClass对象 ===" << endl;
    DerivedClass d1(4, 3);

    cout << "d1.fn1(): ";
    int result1 = d1.fn1();
    cout << "返回值: " << result1 << endl;

    cout << "d1.fn2(): ";
    int result2 = d1.fn2();
    cout << "返回值: " << result2 << endl;




    BaseClass* basePtr = &d1;
    cout << "basePtr->fn1(): ";
    int result3 = basePtr->fn1();
    cout << "返回值: " << result3 << endl;

    cout << "basePtr->fn2(): ";
    int result4 = basePtr->fn2();
    cout << "返回值: " << result4 << endl;





    DerivedClass* derivedPtr = &d1;
    cout << "derivedPtr->fn1(): ";
    int result5 = derivedPtr->fn1();
    cout << "返回值: " << result5 << endl;

    cout << "derivedPtr->fn2(): ";
    int result6 = derivedPtr->fn2();
    cout << "返回值: " << result6 << endl;





    BaseClass* basePtr2 = new DerivedClass(5, 2);
    cout << "basePtr2->fn1(): ";
    int result7 = basePtr2->fn1();
    cout << "返回值: " << result7 << endl;

    cout << "basePtr2->fn2(): ";
    int result8 = basePtr2->fn2();
    cout << "返回值: " << result8 << endl;

    delete basePtr2;

    cout << "d1.BaseClass::fn1(): ";
    int result9 = d1.BaseClass::fn1();
    cout << "返回值: " << result9 << endl;

    cout << "d1.BaseClass::fn2(): ";
    int result10 = d1.BaseClass::fn2();
    cout << "返回值: " << result10 << endl;

    return 0;
}