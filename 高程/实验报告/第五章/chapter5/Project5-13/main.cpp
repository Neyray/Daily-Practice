#include <iostream>
#include "class.h"
using namespace std;

int main() {
    X x(0);
    cout << "Initial: ";
    x.print(); // 0

    Y y;
    y.g(&x); // +1
    cout << "After Y::g (+1): ";
    x.print();

    Z z;
    z.f(&x); // +5
    cout << "After Z::f (+5): ";
    x.print();

    h(&x); // +10
    cout << "After h (+10): ";
    x.print();

    return 0;
}
