#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue<int> q;
    int val;

    cout << "Enter 5 integers to enqueue:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Queue contents: ";
    q.display();

    cout << "Dequeuing elements:" << endl;
    try {
        while (!q.isEmpty()) {
            cout << q.dequeue() << " ";
        }
        cout << endl;
    }
    catch (const underflow_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // 测试空队列出队
    try {
        cout << "Trying to dequeue from empty queue..." << endl;
        q.dequeue();
    }
    catch (const underflow_error& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }

    return 0;
}