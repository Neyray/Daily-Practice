#include "Linked.h"
#include <iostream>
using namespace std;

//1.链栈的初始化和销毁
template <typename T>
LinkStack<T>::LinkStack() {
	head = new LinkNode<T>();
}

template <typename T>
LinkStack<T>::~LinkStack() {
	LinkNode<T>* pre = head, * p = pre->next;
	while (p != NULL) {
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

//2.判断栈是否为空
template <typename T>
bool LinkStack<T>::empty() {
	return head->next == NULL;
}

//3.进栈
template <typename T>
bool LinkStack<T>::push(T e) {
	LinkNode<T>* p = new LinkNode<T>(e);
	p->next = head->next;
	head->next = p;
	return true;
}

//4.出栈
template <typename T>
bool LinkStack<T>::pop(T& e) {
	LinkNode<T>* p;
	if (head->next == NULL)return false;
	p = head->next;
	e = p->data;
	head->next = p->next;
	delete p;
	return true;
}

//5。取栈顶元素
template <typename T>
bool LinkStack<T>::gettop(T& e) {
	LinkNode<T>* p;
	if (head->next == NULL) return false;
	p = head->next;
	e = p->data;
	return true;
}