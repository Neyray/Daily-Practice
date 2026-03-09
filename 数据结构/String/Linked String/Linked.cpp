#include <iostream>
using namespace std;

struct LinkNode {
	char data;
	LinkNode* next;
	//LinkNode() :next(NULL) {}
	LinkNode(char d) :data(d), next(NULL) {}
};

class LinkString {
public:
	LinkNode* head;
	int length;
};

//pre是原串,t是要插入的串
LinkString& InsStr(int i, LinkString pre, LinkString& t) {
	//新建一个空串
	static LinkString s;
	if (i<0 || i>pre.length)
		return s;
	LinkNode* p = pre.head->next, * p1 = t.head->next;
	LinkNode* r = s.head, * q;

	//将当前链串的前i个结点复制到s
	for (int k = 0; k < i; ++k) {
		q = new LinkNode(p->data);
		r->next = q;
		r = q;
		p = p->next;
	}
	//将t中的所有节点复制到s
	while (p1 != NULL) {
		q = new LinkNode(p1->data);
		r->next = q;
		r = q;
		p1 = p1->next;
	}
	//将p及其之后的结点复制到s
	while (p != NULL) {
		q = new LinkNode(p->data);
		r->next = p;
		r = p;
		p = p->next;
	}
	s.length = pre.length + t.length;
	r->next = NULL;
	return s;
}