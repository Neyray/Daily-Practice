#include<iostream>
using namespace std;

const int N = 6;

void print(const int* p, int n)
{
    cout << "{" << *p;
    for (int i = 1; i < n; i++)
        cout << "," << *(p + i);
    cout << "}" << endl;
}

// 示例：尝试修改常量指针（会导致编译错误）
void tryToModify(const int* ptr)
{
    // *ptr = 100; // 错误：不能修改指向常量的指针所指向的值
    cout << "Value pointed to: " << *ptr << endl;
}

int main()
{
    int array[N] = { 10, 20, 30, 40, 50, 60 };

    print(array, N);

    // 使用指向常量的指针
    const int* p = array;
    tryToModify(p);

    return 0;
}