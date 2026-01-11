#include<iostream>
using namespace std;

struct Base1 { int x; };
struct Base2 { float y; };
struct Derived : Base1, Base2 {};

/*
int main() {
    Derived* pd = new Derived;
    pd->x = 1;
    pd->y = 2.0f;

    void* pv = pd;
    Base2* pb = static_cast<Base2*>(pv);  // 这里有问题！

    cout << pd->y << " " << pb->y << endl;

    delete pd;  // 应该删除pd，而不是pb
    return 0;
}
*/

// 修正版本：
int main_fixed() {
    Derived* pd = new Derived;
    pd->x = 1;
    pd->y = 2.0f;

    // 正确的方式：使用dynamic_cast或直接转换
    Base2* pb = pd;  // 隐式转换，正确

    cout << pd->y << " " << pb->y << endl;

    delete pd;
    return 0;
}