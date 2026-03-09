#include "array1.h"
#include <iostream>
using namespace std;

int main() {
    Array<int> arr(10);
    int val;

    cout << "Enter 10 integers:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        arr.setElement(i, val);
    }

    cout << "Original array: ";
    arr.display();

    arr.insertSort();
    cout << "After insert sort: ";
    arr.display();

    // 重新输入数据测试其他排序
    cout << "Enter 10 integers again:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        arr.setElement(i, val);
    }

    arr.selectSort();
    cout << "After select sort: ";
    arr.display();

    // 重新输入数据
    cout << "Enter 10 integers again:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> val;
        arr.setElement(i, val);
    }

    arr.bubbleSort();
    cout << "After bubble sort: ";
    arr.display();

    // 测试顺序查找
    int key;
    cout << "Enter a value to search: ";
    cin >> key;
    int index = arr.seqSearch(key);
    if (index != -1) {
        cout << "Found at index " << index << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}