#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename T>
class CSqQuene {
public:
	T* data;
	int front, rear;

	CSqQuene() {
		data = new T[MaxSize];
		front = rear = 0;
	};
	~CSqQuene() {
		delete[]data;
	}
	bool empty() {
		return (front == rear);
	}
	//进栈操作，主要是移动rear
	bool push(T e) {
		if ((rear + 1) % MaxSize == front)
			return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = e;
		return true;
	}
	//出栈操作，主要是移动front
	bool pop(T& e) {
		if (front == rear)
			return false;
		front = (front + 1) % MaxSize;
		e = data[front];
		return true;
	}
	//取栈头元素，不需要移动front
	bool gethead(T& e) {
		if (front == rear)
			return false;
		int head = (front + 1) % MaxSize;
		e = data[head];
		return true;
	}

};
