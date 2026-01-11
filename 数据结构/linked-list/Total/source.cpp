#include <iostream>
using namespace std;

//单链表,这里的head不包含有效数据
template <typename T>
struct LinkNode {
	T data;
	LinkNode* next;

	LinkNode() :next(NULL) {}
	LinkNode(T d) :data(d), next(NULL) {}
};

template <typename T>
class LinkList {
public:
	LinkNode<T>* head;

	LinkList() {
		head = new LinkNode<T>();
	}
	~LinkList() {
		LinkNode<T>* pre, * p;
		pre = head;
		p = pre->next;
		while (p != NULL) {
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
	//头插法建表
	bool push_head(T e) {
		LinkNode<T>* s = new LinkNode<T>(e);
		s->next = head->next;
		head->next = s;
		return true;
	}
	//尾插法建表
	bool push_back(T e) {
		LinkNode<T>* n = new LinkNode<T>(e);

		if (head->next == NULL) {
			head->next = n;
		}
		else {
			LinkNode<T>* pre = head;
			while (pre->next != NULL) {
				pre = pre->next;
			}
			pre->next = n;
		}

		//无论如何n的指针的下一位一定是NULL!!!
		n->next = NULL;
	}
	//查找序号为i的结点
	LinkNode<T>* geti(int i) {
		if (i < -1)return NULL;

		LinkNode<T>* p = head;           //head就是序号为-1的结点

		int j = -1;
		while (j < i && p->next != NULL) {
			j++;
			p = p->next;
		}
		return p;
	}
	//删除序号为i的结点
	bool Delete(int i) {
		if (i < 0)return false;

		LinkNode<T>* p = geti(i - 1);
		if (p != NULL) {
			LinkNode<T>* s = p->next;
			if (s != NULL) {
				p->next = s->next;
				delete s;
				return true;
			}
			else {
				return false;
			}
		else {
			return false;
		}
		}
	}
	//在序号为i处插入一个结点
	bool Insert(int i, T e) {
		if (i < 0)return false;
		//创建一个新结点
		LinkNode<T>* node = new LinkNode<T>(e);
		LinkNode<T>* p = geti(i - 1);

		if (p != NULL) {
			node->next = p->next;
			p->next = node;
			return true;
		}
		else return false;
	}
	void reverse();
	bool hasCycle();
	LinkNode<T>* findMiddle();
};

//题目1：链表反转（迭代法）
template <typename T>
void LinkList<T>::reverse() {
	//prev位于链表的最后一个节点之后
	LinkNode<T>* prev = NULL;

	LinkNode<T>* curr = head->next;
	while (curr != NULL) {
		//用来存储curr的下一个结点
		LinkNode<T>* next = curr->next;

		//更改指针指向
		curr->next = prev;
		//更新数据
		prev = curr;
		curr = next;
	}
	head->next = prev;
}

//题目2：环形链表检测
template <typename T>
bool LinkList<T>::hasCycle() {
	//空链表的情况
	if (head->next == NULL)return false;

	LinkNode<T>* slow = head->next;
	LinkNode<T>* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)return true;
	}
	return false;
}

//题目3：合并两个有序链表
template <typename T>
static LinkNode<T>* mergeTwoLists(LinkNode<T>* l1, LinkNode<T>* l2) {
	LinkNode<T> dummy(T());
	LinkNode<T>* tail = &dummy;
	while ((l1 != NULL) && (l2 != NULL)) {
		if (l1->data < l2->data) {
			tail->next = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next; // 移动 tail 指针，指向当前链表的末尾
	}
	tail->next = (l1 != NULL) ? l1 : l2; // 如果 l1 或 l2 还有剩余节点，将剩余的链表直接连接到合并链表
	return dummy.next;       // 返回合并后的链表头（跳过 dummy 节点）
}

//题目4：链表中点（快慢指针）
template <typename T>
LinkNode<T>* LinkList<T>::findMiddle() {
	if (!head->next)return NULL;
	LinkNode<T>* slow = head->next;
	LinkNode<T>* fast = head->next;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//双向链表
template <typename T>
struct DLinkNode {
	T data;
	DLinkNode<T>* next, * prior;

	DLinkNode() :next(NULL), prior(NULL) {}
	DLinkNode(T d) :data(d), next(NULL), prior(NULL) {}
};

template <typename T>
class DLinklist {
public:
	//只需要一个头指针即可
	DLinkNode<T>* dhead;

	DLinklist() {
		dhead = new DLinkNode<T>();
	}
	~DLinklist() {
		DLinkNode<T>* pre, * p;
		pre = dhead;
		p = pre->next;
		while (p != NULL) {
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
	//头插法建表
	bool push_head(T e) {
		//新建一个结点
		DLinkNode<T>* node = new DLinkNode<T>();
		node->next = dhead->next;
		if (dhead->next != NULL)
			dhead->next->prior = node;
		node->prior = dhead;
		dhead->next = node;
		return true;
	}
	//尾插法建表
	bool push_back(T e) {
		DLinkNode<T>* node = new DLinkNode<T>();
		if (dhead->next == NULL) {
			dhead->next = node;
			node->prior = dhead;
		}
		else {
			DLinkNode<T>* s = dhead;
			while (s->next != NULL) {
				s = s->next;
			}
			s->next = node;
			node->prior = s;
		}
		//再次强调node是尾结点
		node->next = NULL;
		return true;
	}
	//查找序号为i的结点
	DLinkNode<T>* geti(int i) {
		if (i < -1)return false;

		DLinkNode<T>* p = dhead;
		int j = -1;
		while (j < i && p != NULL) {
			j++;
			p = p->next;
		}
		return p;
	}
	//删除序号为i的结点
	bool Delete(int i) {
		if (i < 0)return false;

		DLinkNode<T>* p = geti(i - 1);
		if (p != NULL) {
			DLinkNode<T>* s = p->next;
			if (s != NULL) {
				s->next = p->next;
				s->next->prior = p;
				delete s;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	//插入序号为i的结点
	bool Insert(int i, T e) {
		//新建一个结点
		DLinkNode<T>* node = new DLinkNode<T>();

		if (i < 0)return false;
		DLinkNode<T>* p = geti(i - 1);

		if (p != NULL) {
			node->next = p->next;
			if (p->next != NULL)
				p->next->prior = node;
			p->next = node;
			node->prior = p;
			return true;
		}
		else
			return false;
	}
};