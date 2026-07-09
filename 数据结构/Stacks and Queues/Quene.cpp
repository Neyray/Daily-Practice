#include <iostream>
using namespace std;

const int MaxSize = 100;
template <typename T>
class SqQuene {
public:
	T* data;
	int front, rear;

	SqQuene() {
		data = new T[MaxSize];
		front = rear = -1;
	}
	~SqQuene() {
		delete[]data;
	}
	bool empty() {
		return (front == rear);
	}
	//加到队列后面
	bool push(T e) {
		if (rear == MaxSize - 1)
			return false;
		rear++;
		data[rear] = e;
		return true;
	}
	//从队头取
	bool pop(T& e) {
		if (front == rear)
			return false;
		front++;
		e = data[front];
		return true;
	}
	//取队头元素，front的指向不能发生变化
	bool gethead(T& e) {
		if (front == rear)
			return false;
		int head = front + 1;
		e = data[head];
		return true;
	}

};

