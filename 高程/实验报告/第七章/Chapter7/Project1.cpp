#include<iostream>
using namespace std;

class Base {
public:
    Base() { a = 0; }
    Base(int i) { a = i; }
protected:
    int a;
};

class Derived : public Base {
public:
    Derived() { b = 0; }
    Derived(int i) { b = i; }
    void Print() { cout << "a=" << a << ", b=" << b << endl; }
private:
    int b;
};

int main() {
    Derived d1;
    Derived d2(12);
    d1.Print();
    d2.Print();
    cin.ignore();
    return 0;
}