#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* i = head;
	ListNode* j = head;
	for (int i = 0; i < n && j != NULL; ++i)
		j = j -> next;
	if (j == NULL) {
		if (i -> next != NULL)
			*i = *(i -> next);
		else return NULL;
		return head;
	}
	while (j -> next != NULL) {
		i = i -> next;
		j = j -> next;
	}
	i -> next = i -> next -> next;
	return head;
}

struct List {
private:
	ListNode vhead;
public:
	ListNode* head;
	int size;
	List() : size(0), vhead(0), head(NULL) {}
	List(initializer_list<int> l) : List() {
		size = l.size();
		ListNode* cr = &vhead;
		for (auto it = begin(l); it != end(l); ++it) {
			cr -> next = new ListNode(*it);
			cr = cr -> next;
		}
		head = vhead.next;
	}
};

ostream& operator<<(ostream& os, ListNode* l) {
	ListNode* cr = l;
	while (cr != NULL) {
		os << cr -> val << " ";
		cr = cr -> next;
	}
	return os;
}

int main(int argc, char *argv[]) {
	List l{1};
	cout << l.head << endl;
	removeNthFromEnd(l.head, 1);
	cout << l.head << endl;
}