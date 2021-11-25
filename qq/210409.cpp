#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int v): val(v), next(nullptr) {}
	
};

bool isIncreasing(ListNode* a) {
	if (a == nullptr || a->next == nullptr)
		return true;
	
	if (a->next->val < a->val)
		return false;
	
	return isIncreasing(a->next);
}

ListNode* reverse(ListNode* a) {
	if (a == nullptr || a->next == nullptr) return a;
	
	ListNode* tail = reverse(a->next);
	a->next->next = a;
	a->next = nullptr;
	return tail;
}

void printList(ListNode* n) {
	while (n != nullptr) {
			printf("%d, ", n->val);
			n = n->next;
	}
	printf("\n");
}

ListNode* mergeSorted(ListNode* a, ListNode* b) {
	ListNode c = ListNode();
	ListNode *p = &c;
	
	if (!isIncreasing(a))
		a = reverse(a);
	
	if (!isIncreasing(b))
		b = reverse(b);
	
	for (; a != nullptr && b != nullptr; ) {
		if (a-> val <= b->val) {
			p->next = a;
			a = a->next;
			p = p-> next;
		} else {
			p->next = b;
			b = b->next;
			p = p->next;
		}
	}
	
	while (a != nullptr) {
		p->next = a;
		a = a->next;
		p = p->next;
	}
	
	while (b != nullptr) {
		p->next = b;
		b = b->next;
		p = p->next;
	}
	
	return c.next;
}

int main() {
	ListNode* a = new ListNode(5);
	a->next = new ListNode(4);
	a->next->next = new ListNode(2);
	a->next->next->next = new ListNode(1);
	printList(a);
	
	ListNode* b = new ListNode(1);
	b->next = new ListNode(3);
	b->next->next = new ListNode(4);
	printList(b);
	
	ListNode* c = mergeSorted(a, b);
	printList(c);
}
