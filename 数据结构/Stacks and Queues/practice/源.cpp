#include <iostream>
#include <vector>
using namespace std;

class CSqQueue {
public:
	int maxsize;
	int* data;
	int front, rear;

	//构造函数
	CSqQueue(int m) :maxsize(m) {
		data = new int[maxsize];
		front = rear = 0;
	}
	//析构函数
	~CSqQueue() {
		delete[]data;
	}
	//判断是否为空
	bool empty() {
		return (front == rear);
	}
	//进队列
	bool push(int e) {
		if ((rear + 1) % maxsize == front)
			return false;
		rear = (rear + 1) % maxsize;
		data[rear] = e;
		return true;
	}
	//出队列
	bool pop(int& e) {
		if (front == rear)
			return false;
		front = (front + 1) % maxsize;
		e = data[front];
		return true;
	}
	bool gethead(int& e) {
		if ((front + 1) % maxsize == 0)
			return false;
		int head = (front + 1) % maxsize;
		e = data[head];
		return true;
	}
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	if (m == 0 || m == 1) {
		cout << "none";
		return 0;
	}

	CSqQueue c(n + 1);
	for (int i = 1; i <= n; ++i) {
		c.push(i);
	}

	//调整队列头部位置
	for (int i = 0; i < q - 1; ++i) {
		int temp;
		c.pop(temp);
		c.push(temp);
	}

	int count = n;
	while (count >= 2) {
		for (int i = 0; i < m - 1; ++i) {
			int temp;
			c.pop(temp);
			c.push(temp);
		}
		int discard;
		c.pop(discard);
		count--;
	}
	int temp;
	c.pop(temp);
	cout << temp;

	return 0;
}