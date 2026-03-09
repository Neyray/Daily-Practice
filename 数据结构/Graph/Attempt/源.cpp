#include <iostream>
#include <vector>
#include <string>

using namespace std;

void nullPointerDereference() {
    string* ptr = nullptr;
    cout << "String length: " << ptr->length() << endl; // ´íÎó1
}

void divisionByZero() {
    int a = 10, b = 0;
    int result = a / b; // ´íÎó2
    cout << "Result: " << result << endl;
}

void outOfBounds() {
    vector<int> vec = { 1, 2, 3 };
    for (int i = 0; i <= 3; i++) { // ´íÎó3
        cout << vec[i] << endl;
    }
}

void invalidIterator() {
    vector<int> nums = { 1, 2, 3 };
    auto it = nums.begin();
    nums.push_back(4); // ´íÎó4
    cout << *it << endl;
}

void memoryLeak() {
    int* arr = new int[100]; // ´íÎó5
    // Íü¼Çdelete[]
}

int main() {
    // Ñ¡ÔñÒª´¥·¢µÄ´íÎó
    cout << "Select error type (1-5):\n";
    cout << "1. Null Pointer Dereference\n";
    cout << "2. Division by Zero\n";
    cout << "3. Out of Bounds\n";
    cout << "4. Invalid Iterator\n";
    cout << "5. Memory Leak\n";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1: nullPointerDereference(); break;
    case 2: divisionByZero(); break;
    case 3: outOfBounds(); break;
    case 4: invalidIterator(); break;
    case 5: memoryLeak(); break;
    default: cout << "Invalid choice\n";
    }

    return 0;
}