#pragma once
template <typename T>
struct LinkNode {
	T data;
	LinkNode* next;
	LinkNode() :next(NULL);
	LinkNode(T d) :data(d), next(NULL);
};

template <typename T>
class LinkStack {
public:
	LinkNode<T>* head;
	LinkStack();
	~LinkStack();
	bool empty();
	bool push(T e);
	bool pop(T& e);
	bool gettop(T& e);
};