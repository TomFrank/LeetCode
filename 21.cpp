#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode* cr = &dummy;
#define NN(l) ((l) != NULL)
#define NA (NN(l1) && NN(l2))
#define NW(l) cr -> next = new ListNode(l -> val);\
			  cr = cr -> next;\
			  l = l -> next
#define WW(l,b) while (NA && (l1 -> val > l2 -> val ? b : !b)) { NW(l); }
#define WH(l) while (NN(l)) { NW(l); }
	while (NA) {
		WW(l2, 1);
		WW(l1, 0);
	}
	WH(l1);
	WH(l2);
	return dummy.next;
}

ostream& operator<<(ostream& os, ListNode* l) {
	ListNode* cr = l;
	while (cr != NULL) {
		os << cr -> val << " ";
		cr = cr -> next;
	}
	return os;
}

int main(int argc, char *argv[]) {
	List l1{1,2,4};
	List l2{1,3,4};
	auto ans = mergeTwoLists(l1.head, l2.head);
	cout << ans << endl;
}



