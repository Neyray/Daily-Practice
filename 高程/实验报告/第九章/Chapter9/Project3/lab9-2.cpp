#include "Link.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList<int> A, B;
    int val;

    cout << "Enter 5 integers for list A:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> val;
        A.insertAtEnd(val);
    }

    cout << "Enter 5 integers for list B:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> val;
        B.insertAtEnd(val);
    }

    cout << "List A: ";
    A.display();
    cout << "List B: ";
    B.display();

    A.concatenate(B);
    cout << "After concatenation, List A: ";
    A.display();
    cout << "List B (should be empty): ";
    B.display();

    return 0;
}