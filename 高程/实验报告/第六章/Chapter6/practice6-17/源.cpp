#include<iostream>
using namespace std;

int main()
{
    int a = 5;
    int* p = &a;
    //*p = 9;  // 错误：指针p未初始化，指向随机内存地址
    cout << "the value at p:" << *p;
    return 0;
}