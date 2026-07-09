#include <iostream>
using namespace std;

template <typename T>
struct LinkNode {
	T data;
	LinkNode* next;
	//构造函数
	LinkNode() :next(NULL) {}
	LinkNode(T d) :data(d), next(NULL) {}
};


//不带头节点，仅有尾结点指针的循环单链表链栈
template <typename T>
class Stack {
public:
	//链栈的尾结点指针
	LinkNode<T>* rear;

	//构造函数
	Stack() :rear(NULL) {}
	//析构函数
	~Stack() {
		//空链表直接返回
		if (rear == NULL)return;
		LinkNode<T>* pre = rear; , * p = pre->next;
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

	//进栈算法
	bool push(T e) {
		//新建结点p
		LinkNode<T>* p = new LinkNode<T>(e);
		if (empty()) {
			rear = p;
			rear = rear->next;
		}
		else {
			//将结点p插入结点rear的后面
			p->next = rear->next;
			rear->next = p;
		}
		return true;
	}

	//出栈算法
	bool pop(T& e) {
		LinkNode<T>* p;
		if (empty())return false;
		//栈中只有一个结点的情况
		if (rear->next == rear) {
			p = rear;
			rear = NULL;
		}
		else {
			p = rear->next;
			rear->next = p->next;
		}
		e = p->data;
		delete p;
		returnr true;
	}

	//取栈顶元素
	bool gettop(T& e) {
		if (empty())return false;
		e = rear->next->data;
		return true;
	}

	//取栈底元素
	T getBottom() {
		if (empty())throw "栈空";
		return rear->data;
	}
};