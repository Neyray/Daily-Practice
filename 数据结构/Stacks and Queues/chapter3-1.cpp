/*【问题描述】n只猴子要选猴王，所有猴子按1,2，…，n编号围坐一圈，从第1只开始按1,2，…，m报数，凡报到m号的猴子退出圈外，如此循环报数，直到圈内剩下一只猴子时，这个猴子就是猴王。编写一个程序，计算出猴子的出队顺序以及最后的猴王号码？

【输入形式】n
【输出形式】出队顺序
【样例输入】10
【样例输出】出队顺序：3 6 9 2 7 1 8 5 10 4

                     猴王为：4   */

#include <iostream>
#include <vector>
using namespace std;

class CSqQuene {
public:
	int maxsize;
	int* data;
	int front, rear;

	//构造函数
	CSqQuene(int m) :maxsize(m) {
		data = new int[maxsize];
		front = rear = 0;
	}
	//析构函数
	~CSqQuene() {
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
	int N;
	cin >> N;
	//构造函数的时候要比设定大小大一位!!!
	CSqQuene c(N + 1);

	for (int i = 1; i <= N; ++i) {
		c.push(i);
	}

	vector<int> results;

	int m = 3;
	while (results.size() < static_cast<size_t>(N - 1)) {
		//将第m个猴子之前的猴子移到后面
		for (int i = 0; i < m - 1; ++i) {
			int temp = 0;
			c.pop(temp);
			c.push(temp);
		}
		int e = 0;
		c.pop(e);
		results.push_back(e);
	}
	int monkeyKing;
	c.pop(monkeyKing);
	results.push_back(monkeyKing);


	for (size_t i = 0; i < results.size(); ++i) {
		cout << results[i] << " ";
	}
	cout << endl;
	cout << monkeyKing;

	return 0;
}