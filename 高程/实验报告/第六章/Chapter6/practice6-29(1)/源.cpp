#include<iostream>
using namespace std;

int main()
{
    int arr[] = { 1, 2, 3 };

    // 安全的方式：使用相同类型的指针
    int* p = &arr[0];
    *p = 5;  // 安全操作

    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    // 如果确实需要类型转换，应该确保内存访问安全
    double value = 5.0;
    // 先分配足够的double类型内存
    double* safeDouble = new double(value);
    // 然后进行安全的类型转换或内存拷贝

    cout << "Safe double value: " << *safeDouble << endl;
    delete safeDouble;

    return 0;
}