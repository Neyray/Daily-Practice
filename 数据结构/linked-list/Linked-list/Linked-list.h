#pragma once
template <typename T>
struct LinkNode            //每个结点均为LinkNode类型
{
	T data;
	LinkNode<T>* next;

	LinkNode() :next(NULL) {}
	LinkNode(T d) :data(d), next(NULL) {}
	void CreateListF(T a[], int n);
	void CreateListR(T a[], int n);
	LinkNode<T>* geti(int i);
};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	void Add(T e);
	int Getlength();
	bool GetElem(int i, T& e);
	bool SetElem(int i, T e);
	int GetNo(T e);
	bool Insert(int i, T e);
	bool Delete(int i);
	void DispList();

	LinkNode<T>* head;
};