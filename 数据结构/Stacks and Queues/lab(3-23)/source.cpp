/*【问题描述】

  小米和爸爸一起玩游戏，爸爸随机抽取几张纸牌，将正面朝下，然后依次执行如下步骤：

 （1）第一步，将最上面一张纸牌移到最底下，新的最上面纸牌翻开放一边，该纸牌是梅花1（A）。

 （2）第二步，将最上面一张纸牌移到最底下，这样做两次，两次完后将新的最上面纸牌翻开放一边，该纸牌是梅花2。

 （3）第三步，将最上面一张纸牌移到最底下，这样做三次，三次完后新的最上面纸牌翻开放一边，该纸牌是梅花3。

 （4）以此类推，第n步做n次移动后新的最上面纸牌翻开放一边，该纸牌是梅花n。

  小米说爸爸一定提前安排了纸牌顺序，并且很快推算出纸牌初始顺序，请用循环队列编写程序验证纸牌初始顺序。

【输入形式】

第一行输入一个正整数m，表示测试用例数（接下来的行数位m），接着每行输入一个样例（即n）

【输出形式】

输出m行，每行对应相应测试用例的纸牌初始顺序，即1到n这n个整数的某种排列（以空格隔开）

【样例输入】

2

3

4

【样例输出】

3 1 2

2 1 4 3 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CSqQueue {
public:
	int* data;
	int front, rear, maxSize;

	CSqQueue(int m) :maxSize(m + 1) {
		data = new int[maxSize];        //大小已经固定了
		front = rear = 0;
	}
	~CSqQueue() {
		delete[]data;
	}
	bool empty() {
		return (front == rear);
	}
	bool push(int e) {
		if ((rear + 1) % maxSize == front)
			return false;
		//先更新
		rear = (rear + 1) % maxSize;
		data[rear] = e;
		return true;
	}
	bool pop(int& e) {
		if (front == rear)
			return false;
		front = (front + 1) % maxSize;
		e = data[front];
		return true;
	}
	bool gettop(int& e) {
		if (front == rear)
			return false;
		int head = (front + 1) % maxSize;
		e = data[head];
		return true;
	}
};

void Solution(int n) {
	vector<int> ans(n + 1);
	CSqQueue sq(n);

	for (int i = n; i >= 1; i--) {
		sq.push(i);

		for (int j = 0; j < i; j++) {
			int last;
			sq.pop(last);
			sq.push(last);
		}
	}

	vector<int> result;
	int temp;
	while (sq.pop(temp)) {
		result.push_back(temp);
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		Solution(n);
		cout << endl;
	}
	return 0;
}