#include "SqStack.h";
#include <iostream>;
using namespace std;

const int MaxSize = 5;

//1.顺序栈的初始化和销毁
template <typename T>
SqStack<T>::SqStack() {
	data = new T[MaxSize];
	top = -1;
}

template <typename T>
SqStack<T>::~SqStack() {
	delete[]data;
}

//2.判断栈是否为空
template <typename T>
bool SqStack<T>::empty() {
	return top == -1;
}

//3.进栈
template <typename T>
bool SqStack<T>::push(T e) {
	if (top == MaxSize - 1)
		return false;
	top++;
	data[top] = e;
	return true;
}

//4.出栈
template <typename T>
bool SqStack<T>::pop(T& e) {
	if (empty())
		return false;
	e = data[top];
	top--;
	return true;
}

//5.取栈顶元素
template <typename T>
bool SqStack<T>::gettop(T& e) {
	if (empty())
		return false;
	e = data[top];
	return true;
}