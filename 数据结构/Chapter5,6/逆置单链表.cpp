#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
struct LinkNode {
	T data;
	LinkNode* next;
	LinkNode(T d) :data(d), next(NULL) {}
};

LinkNode<int>* Reverse(LinkNode<int>* p) {
	if (p == NULL)
		return NULL;
	if (p->next == NULL)
		return p;
	else {
		LinkNode<int>* np;
		//求解子问题
		np = Reverse(p->next);
		//将p作为尾结点
		p->next->next = p;
		p->next = NULL;

		return np;
	}
}

LinkNode<int>* buildList(LinkNode<int>* head, const string& str) {
	stringstream ss(str);
	int value;
	while (ss >> value) {
		LinkNode<int>* node = new LinkNode<int>(value);
		if (head == NULL || value <= head->data) {
			node->next = head;
			head = node;
		}
		else {
			LinkNode<int>* curr = head;
			while (curr->next != NULL && curr->next->data <= value) {
				curr = curr->next;
			}
			node->next = curr->next;
			curr->next = node;
		}
	}
	return head;
}


void print(LinkNode<int>* head) {
	LinkNode<int>* curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	LinkNode<int>* head = NULL;

	string line;
	getline(cin, line);

	head = buildList(head, line);
	print(head);

	head = Reverse(head);
	print(head);

	return 0;
}