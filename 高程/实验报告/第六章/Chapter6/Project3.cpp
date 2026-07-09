#include<iostream>
using namespace std;

void tryToModifyArray(const int[]);

int main()
{
    int a[] = { 10, 20, 30 };

    tryToModifyArray(a);

    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    return 0;
}

void tryToModifyArray(const int b[])
{
    // 以下代码会导致编译错误，因为b是const数组
    b[0] /= 2;
    b[1] /= 2;
    b[2] /= 2;
}