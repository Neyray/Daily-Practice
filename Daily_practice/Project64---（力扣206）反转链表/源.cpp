#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(NULL) {}
	ListNode(int v) :val(v), next(NULL) {}
};

ListNode* buildList(vector<int>nums) {
	if (nums.empty()) return NULL;

	ListNode* head = new ListNode(nums[0]);
	ListNode* curr = head;
	for (int i = 1; i < nums.size(); ++i) {
		ListNode* next = new ListNode(nums[i]);
		curr->next = next;
		curr = next;
	}
	return head;
}


ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* prev = NULL, * curr = head;
	while (curr != NULL) {
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

int main() {
	vector<int>nums = { 1,2,3,4,5 };
	ListNode* head = buildList(nums);
	ListNode* curr1 = head;
	while (curr1 != NULL) {
		cout << curr1->val << " ";
		curr1 = curr1->next;
	}

	cout << endl;

	//注意不要进行重定义
	head = reverseList(head);
	ListNode* curr2 = head;
	while (curr2 != NULL) {
		cout << curr2->val << " ";
		curr2 = curr2->next;
	}

	return 0;
}