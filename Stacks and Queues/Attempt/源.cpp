#include <iostream>
#include <sstream>
using namespace std;

const int MaxSize = 5;

//顺序栈
template <typename T>
class SqStack {
public:
	T* data;       //实际上相当于一个数组，用来存储数组中的元素
	int top;

	SqStack() {
		data = new T[MaxSize];
		top = -1;
	}
	~SqStack() {
		delete[]data;
	}
	bool empty() {
		return top == -1;
	}
	bool push(T e) {
		if (top == MaxSize - 1)
			return false;
		top++;
		data[top] = e;
		return true;
	}
	bool pop(T& e) {
		if (empty())
			return false;
		e = data[top];
		top--;
		return true;
	}
	bool gettop(T& e) {
		if (empty())
			return false;
		e = data[top];
		return true;
	}
	bool isBracketValid(const string& s);
};

//链栈，只含有头结点
template <typename T>
struct LinkNode {
	T data;
	LinkNode<T>* next;

	LinkNode() :next(NULL);
	LinkNode(T d) :data(d), next(NULL);
};

template <typename T>
class LinkStack {
public:
	LinkNode<T>* head;

	//构造函数
	LinkStack() {
		head = new LinkNode<T>();
	}

	//析构函数
	~LinkStack() {
		LinkNode<T>* pre = head, p = pre->next;
		while (p != NULL) {
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}

	//从头插
	bool push(T e) {
		LinkNode<T>* p = new LinkNode<T>(e);
		//注意！head是不发生移动的
		p->next = head->next;
		head->next = p;
		return true;
	}

	//从头出
	bool pop(T& e) {
		LinkNode<T>* p;
		if (head->next == NULL)
			return false;
		p = head->next;
		e = p->data;

		head->next = p->next;
		delete p;
		return true;
	}
	bool gettop(T& e) {
		if (head->next == NULL)
			return false;
		e = head->next->data;
		return true;
	}
	int evalRPN(const string& tokens);
};

//循环单链表链栈，不带头结点，只含有尾结点
template <typename T>
struct CLinkNode {
	T data;
	CLinkNode<T>* next;
	CLinkNode() :next(NULL) {}
	CLinkNode(T d) :data(d), next(NULL) {}
};

template <typename T>
class CLinkStack {
public:
	CLinkNode<T>* rear;

	CLinkStack() :rear(NULL) {}
	~CLinkStack() {
		if (rear == NULL)
			return;
		CLinkNode<T>* pre = rear, p = pre->next;
		while (p != rear) {
			delete pre;
			pre = p;
			p = pre->next;
		}
		delete pre;
	}

	bool empty() {
		return rear == NULL;
	}
	bool push(T e) {
		CLinkNode<T>* p = new CLinkNode<T>(e);
		if (empty()) {
			rear = p;
			rear = rear->next;
		}
		else {
			//把结点p插入到rear的后面
			p->next = rear->next;
			rear->next = p;
		}
		return true;
	}
	//出栈操作，从头出
	bool pop(T& e) {
		CLinkNode<T>* p;
		if (empty())
			return false;
		if (rear->next == rear) {
			p = rear->next;
			rear = NULL;
		}
		else {
			p = rear->next;
			rear->next = p->next;
		}
		e = p->data;
		delete p;
		return true;
	}
	//获取栈头元素
	template <typename T>
	bool gettop(T& e) {
		if (empty())return false;
		e = rear->next->data;
		return true;
	}
	//获取栈底元素
	T getbottom(T& e) {
		if (empty())throw "栈空";
		return rear->data;
	}
};


//一.栈专题


//题目1：顺序栈实现括号匹配
template <typename T>
bool SqStack<T>::isBracketValid(const string& s) {
	SqStack<char> st;
	for (char c : s) {
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		}
		else {
			if (st.empty())return false;
			char top;
			st.gettop(top);
			if ((c == ')' && top != '(') ||
				(c == ']' && top != '[') ||
				(c == '}' && top != '{')) {
				return false;
			}
			st.pop(top);
		}
	}
	return st.empty();
}

//题目2：链栈实现表达式求值（简化版）
template <typename T>
int LinkStack<T>::evalRPN(const string& tokens) {
	LinkStack<int>st;
	istringstream iss(tokens);
	string token;

	while (iss >> token) {
		if (isdigit(tokems[0])) {
			st.push(stoi(token));           //stoi是将字符串转换为整数的运算符
		}
		else {
			int a, b;
			st.pop(b);
			st.pop(a);
			if (token == "+")st.push(a + b);
			else if (token == "-")st.push(a - b);
			else if (token == "*")st.push(a * b);
			else st.push(a / b);
		}
	}
	int res;
	st.pop(res);
	return res;
}

//非循环队列
template <typename T>
class SqQuene {
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
		return (rear == front);
	}
	//把元素加到队列后面
	bool push(T e) {
		if (rear == MaxSize - 1)
			return false;
		rear++;
		data[rear] = e;
		return true;
	}
	//从队头取出元素
	bool pop(T& e) {
		if (front == rear)return false;
		front++;
		e = data[front];
		return true;
	}
	//获取栈头元素
	bool gettop(T& e) {
		if (front == rear)return false;
		T head = front;
		head++;
		e = data[head];
		return true;
	}
};

//循环队列
template <typename T>
class CSqQuene {
public:
	T* data;
	int front, rear;

	CSqQuene() {
		data = new T[MaxSize];
		front = rear = 0;
	}
	~CSqQuene() {
		delete[]data;
	}
	bool empty() {
		return (front == rear);
	}
	bool push(T e) {
		if ((rear + 1) % MaxSize == 0)
			return false;
		rear = (rear + 1) % MaxSize;
		data[rear] = e;
		return true;
	}
	bool pop(T& e) {
		if (front == rear)
			return false;
		front = (front + 1) % MaxSize;
		e = data[front];
		return true;
	}
	//head是不需要动的
	bool gettop(T& e) {
		if (front == rear)
			return false;
		T head = (front + 1) % MaxSize;
		e = data[head];
		return true;
	}
	int josephus(int n, int m);
};

//二.队列专题

//题目1：循环队列实现击鼓传花
template <typename T>
int CSqQuene<T>::josephus(int n, int m) {
	CSqQueue<int> q;
	for (int i = 0; i < n; ++i) q.push(i);
	while (!q.empty()) {
		for (int i = 0; i < m - 1; ++i) {
			int val;
			q.pop(val);
			q.push(val);
		}
		int eliminated;
		q.pop(eliminated);
		if (q.empty()) return eliminated;
	}
	return -1;
}