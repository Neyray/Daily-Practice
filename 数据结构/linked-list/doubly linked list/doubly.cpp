#include "doubly linked.h"
#include <iostream>
using namespace std;

//1.用头插法建表
template <typename T>
void DLinkList<T>::CreateListF(T a[], int n) {
	for (int i = 0; i < n; ++i) {
		s = new DLinkNode<T>(a[i]);
		s->next = dhead->next;
		if (dhead->next != NULL)
			dhead->next->prior = s;
		s->prior = dhead;
		dhead->next = s;
	}
}

//2.用尾插法建表
template <typename T>
void DLinkList<T>::CreateListR(T a[], int n) {
	DLinkNode<T>* s, * r;
	r = dhead;
	for (int i = 0; i < n; ++i) {
		s = new DLinkNode<T>(a[i]);
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

//3.插入
template <typename T>
bool DLinkList<T>::Insert(int i, T e) {
	if (i < 0)return false;
	DLinkNode<T>* s = new DLinkNode<T>(e);
	DLinkNode<T>* p = geti(i - 1);
	if (p != NULL) {
		s->next = p->next;
		if (p->next != NULL)
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
	else
		return false;
}

//4.删除
template <typename T>
bool DLinkList<T>::Delete(int i) {
	if (i < 0)return false;
	DLinkNode<T>* p = geti(i - 1);
	if (p != NULL) {
		p->prior->next = p->next;
		if (p->next != NULL)
			p->next->prior = p->prior;
		delete p;
		return true;
	}
	else
		return false;
}

//5.查找元素位置
template <typename T>
DLinkNode<T>* geti(int i) {
	if (i < -1)return NULL;
	LinkNode<T>* p = dhead;
	int j = -1;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	return p;
}