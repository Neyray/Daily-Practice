#include <iostream>
using namespace std;

class Ctype
{
private:
    int a;
    static int s;
public:
    static void Print();
    Ctype();
};

void Ctype::Print()
{
    //cout << "a = " << ++a << endl;
    cout << "s = " << ++s << endl;
}

Ctype::Ctype()
{
    a = 0;
    s++;
    cout << "a=" << ++a << endl;
}

int Ctype::s = 0;

int main()
{
    Ctype::Print();  // 未定义对象，通过类名调用静态成员函数

    Ctype c1, c2;
    c1.Print();
    c2.Print();

    Ctype c3;
    c3.Print();

    return 0;
}
