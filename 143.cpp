#include "./lttools.cpp"

class Solution {
public:
	
	ListNode* reverse(ListNode* h) {
		auto pre = h;
		while (h != nullptr && h->next != nullptr) {
			auto t = h->next->next;
			h->next->next = pre;
			pre = h->next;
			h->next = t;
		}
		return pre;
	}
	
	ListNode* midNode(ListNode* head) {
		auto i=head;
		auto j=head;
		while (j != nullptr && j->next != nullptr) {
			i=i->next;
			j=j->next->next;
		}
		return i;
	}
	
	void merge(ListNode* head, ListNode* tail) {
		auto p = head->next;
		auto q = tail->next;
		while (p && q) {
			head->next = tail;
			tail->next = p;
			head = p;
			tail = q;
			p=p->next;
			q=q->next;
		}
		return ;
	}
	
	void reorderList(ListNode* head) {
		auto m = midNode(head);
		auto t = reverse(m);
		merge(head, t);
	}
};

int main(int argc, char *argv[]) {
	auto l = LT::list_from({1,2,3,4,5,6,7});
	Solution().reorderList(l);
	LT::print(l);
}