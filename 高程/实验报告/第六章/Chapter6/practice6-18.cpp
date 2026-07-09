#include<iostream>
using namespace std;

int fn1()
{
    int* p = new int(5);
    return *p;  // 内存泄漏：没有delete
}

int main()
{
    int a = fn1();
    cout << "the value of a is:" << a;
    return 0;
}