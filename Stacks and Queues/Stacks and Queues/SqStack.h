#pragma once
template <typename T>
class SqStack {
	T* data;
	int top;

	SqStack();
	~SqStack();
	bool empty();
	bool push(T e);
	bool pop(T& e);
	bool gettop(T& e);
};