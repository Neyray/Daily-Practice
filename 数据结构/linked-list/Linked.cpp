#include "Linked-list.h"
#include <iostream>
using namespace std;

//1.用头插法建表
template <typename T>
void LinkNode<T>::CreateListF(T a[], int n) {
	for (int i = 0; i < n; ++i) {
		LinkNode<T>* s = new LinkNode<T>(a[i]);      //创建数据节点s
		s->next = head->next;           //将结点s插入head结点的后面
		head->next = s;         //head的位置不会发生变化
	}
}

//2.用尾插法建表
template <typename T>
void LinkNode<T>::CreateListR(T a[], int n) {
	LinkNode<T>* s, * r;     //r是尾指针，始终指向当前链表的尾结点
	r = head;//初始化
	for (int i = 0; i < n; ++i) {
		s = new LinkNode<T>(a[i]);
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//3.查找序号为i的结点
template <typename T>
LinkNode<T>* geti(int i) {
	if (i < -1)return NULL;
	LinkNode<T>* p = head;
	int j = -1;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	return p;
}

//4.单链表的初始化和销毁
template <typename T>
LinkList<T>::LinkList() {
	head = new ListNode<T>();
}

template <typename T>
LinkList<T>::~LinkList() {
	LinkNode<T>* pre, * p;
	pre = head;
	p = pre->next;
	while (p != NULL) {
		delete = pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}

//5.将元素e的结点添加到单链表末尾
template <typename T>
void LinkList<T>::Add(T e) {
	LinkNode<T>* s = new LinkNode<T>(e);         //新建结点e
	LinkNode<T>* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = s;
}

//6.求单链表的长度
template <typename T>
int LinkList<T>::Getlength() {
	LinkNode<T>* p = head;
	int cnt = 0;
	while (p->next != NULL) {
		cnt++;
		p = p->next;
	}
	return cnt;
}

//7.求单链表中序号为i的结点值
template <typename T>
bool LinkList<T>::GetElem(int i, T& e) {
	if (i < 0)return false;
	LinkNode<T>* p = geti(i);
	if (p->next != NULL) {
		e = p->data;
		return true;
	}
	else
		return false;
}

//8.设置单链表中序号为i的结点值
template <typename T>
bool LinkList<T>::SetElem(int i, T e) {
	if (i < 0)return false;
	LinkNode<T>* p = geti(i);
	if (p != NULL) {
		p->data = e;
		return true;
	}
	return false;
}

//9.求链表中第一个值为e的结点的符号
template <typename T>
int LinkList<T>::GetNo(T e) {
	int j = 0;
	LinkNode<T>* p = head->next;          //之所以令p=head->next而不是p=head的原因是之后要调用p->data
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return -1;
	else
		return j;
}

//10.在单链表中插入元素e作为第i个结点
template <typename T>
bool LinkList<T>::Insert(int i, T e) {
	if (i < 0)return false;
	LinkNode<T>* p = geti(i - 1);
	if (p != NULL) {
		LinkNode<T>* s = new LinkNode<T>(e);         //建立新结点s
		s->next = p->next;
		p->next = s;
		return true;
	}
	else
		return false;
}

//11.在单链表中删除序号为i的结点
template <typename T>
bool LinkList<T>::Delete(int i) {
	if (i < 0)return false;
	LinkNode<T>* p = geti(i - 1);
	if (p != NULL) {
		LinkNode<T>* q = p->next;
		if (q != NULL) {
			p->next = q->next;
			delete q;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

//12.输出单链表中的所有结点值
template <typename T>
void LinkList<T>::DispList() {
	LinkNode<T>* p;
	p = head->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}