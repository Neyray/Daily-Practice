#include<iostream>
using namespace std;

class A {
public:
    A(int i) { a = i; cout << "A Constructor" << endl; }
    void disp() { cout << "a=" << a << endl; }
    ~A() { cout << "A Destructor" << endl; }
private:
    int a;
};

class B {
public:
    B(int j) { b = j; cout << "B Constructor" << endl; }
    void disp() { cout << "b=" << b << endl; }
    ~B() { cout << "B Destructor" << endl; }
private:
    int b;
};

class C : public B, public A {
public:
    C(int k) : A(k + 2), B(k - 2) {
        c = k;
        cout << "C Constructor" << endl;
    }
    void disp() {
        A::disp();
        B::disp();
        cout << "c=" << c << endl;
    }
    ~C() { cout << "C Destructor" << endl; }
private:
    int c;
};

int main() {
    C obj(10);
    obj.disp();



    cin.ignore();
    return 0;
}