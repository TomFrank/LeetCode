#include "./lttools.cpp"

class Solution {
public:
	static
	ListNode* middleNode(ListNode* head) {
		auto i=head;
		auto j=head;
		while (j != nullptr && j->next != nullptr) {
			i=i->next;
			j=j->next->next;
		}
		return i;
	}
};

int main(int argc, char *argv[]) {
	auto inputs = {
		LT::list_from("[1,2,3,4,5]"),
		LT::list_from("[1,2,3,4,5,6]")
	};
	LT::batch_test(inputs, Solution::middleNode);
}
