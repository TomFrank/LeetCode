#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL) {}
};

ostream& operator<<(ostream& os, ListNode* root) {
	auto crr = root;
	while (crr != NULL) {
		os << crr -> val << " ";
		crr = crr -> next;
	}
	return os << "\n";
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	auto root = new ListNode(-1);
	auto crr = root;
	while (l1 != NULL && l2 != NULL) {
		crr -> next = new ListNode(l1 -> val + l2 -> val);
		l1 = l1 -> next;
		l2 = l2 -> next;
		crr = crr -> next;
	}
	while (l1 != NULL) {
		crr -> next = new ListNode(l1 -> val);
		l1 = l1 -> next;
		crr = crr -> next;
	}
	while (l2 != NULL) {
		crr -> next = new ListNode(l2 -> val);
		l2 = l2 -> next;
		crr = crr -> next;
	}
	crr = root -> next;
	while (crr != NULL) {
		if (crr -> val > 9) {
			crr -> val -= 10;
			if (crr -> next != NULL)
				++(crr -> next -> val);
			else crr -> next = new ListNode(1);
		}
		crr = crr -> next;
	}
	return root -> next;
}

int main(int argc, char *argv[]) {
	ListNode* r = new ListNode(8);
	r -> next = new ListNode(5);
	r -> next -> next = new ListNode(5);
	
	auto ans = addTwoNumbers(r->next->next, r->next->next);
//	cout << r;
	cout << ans;
}