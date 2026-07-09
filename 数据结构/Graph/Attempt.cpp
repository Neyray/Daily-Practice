#include <iostream>
#include <vector>
#include <string>

using namespace std;

void nullPointerDereference() {
    string* ptr = nullptr;
    cout << "String length: " << ptr->length() << endl; // 错误1
}

void divisionByZero() {
    int a = 10, b = 0;
    int result = a / b; // 错误2
    cout << "Result: " << result << endl;
}

void outOfBounds() {
    vector<int> vec = { 1, 2, 3 };
    for (int i = 0; i <= 3; i++) { // 错误3
        cout << vec[i] << endl;
    }
}

void invalidIterator() {
    vector<int> nums = { 1, 2, 3 };
    auto it = nums.begin();
    nums.push_back(4); // 错误4
    cout << *it << endl;
}

void memoryLeak() {
    int* arr = new int[100]; // 错误5
    // 忘记delete[]
}

int main() {
    // 选择要触发的错误
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