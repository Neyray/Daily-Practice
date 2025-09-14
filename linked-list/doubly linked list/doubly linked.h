#pragma once
template <typename T>
struct DLinkNode {
	T data;
	DLinkNode<T>* next;
	DLinkNode<T>* prior;

	//无参构造函数
	DLinkNode() :next(NULL), prior(NULL) {}
	//有参构造函数
	DLinkNode(T d) :data(d), next(NULL), prior(NULL) {}
};

template <typename T>
class DLinkList {
public:
	//链表，只需要一个头指针作为初始数据即可
	DLinkNode<T>* dhead;
	void CreateListF(T a[], int n);
	void CreateListR(T a[], int n);
	bool Insert(int i, T e);
	bool Delete(int i);
};
